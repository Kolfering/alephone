#include "AudioPlayer.h"
#include "OpenALManager.h"

AudioPlayer::AudioPlayer(int rate, bool stereo, bool sixteen_bit) {
	this->rate = rate;
	format = GetCorrespondingFormat(stereo, sixteen_bit);
}

bool AudioPlayer::AssignSource() {
	if (audio_source.source) return true;
	audio_source = OpenALManager::Get()->PickAvailableSource();
	return this->audio_source.source && SetUpALSourceInit();
}

void AudioPlayer::ResetSource() {
	if (audio_source.source) {
		alSourceStop(audio_source.source);

		//let's be sure all of our buffers are detached from the source
		alSourcei(audio_source.source, AL_BUFFER, 0);

		for (auto& buffer : audio_source.buffers) {
			buffer.queue_state = false;
		}
	}
}

//Get back the source of the player
AudioPlayer::AudioSource AudioPlayer::RetrieveSource() {
	ResetSource();
	AudioPlayer::AudioSource resetSource = audio_source;
	audio_source.source = 0;
	return resetSource;
}

void AudioPlayer::UnqueueBuffers() {
	ALint nbBuffersProcessed;
	alGetSourcei(audio_source.source, AL_BUFFERS_PROCESSED, &nbBuffersProcessed);

	while (nbBuffersProcessed > 0) {
		ALuint bufid;
		alSourceUnqueueBuffers(audio_source.source, 1, &bufid);
		auto buffer = std::find_if(std::begin(audio_source.buffers), std::end(audio_source.buffers), [&bufid](const AudioPlayerBuffer buffer) -> ALuint {return buffer.buffer_id == bufid; });
		buffer->queue_state = false;
		nbBuffersProcessed--;
	}
}

void AudioPlayer::FillBuffers() {

	UnqueueBuffers(); //First we unqueue buffers that can be

	for (auto& buffer : audio_source.buffers) {
		if (!buffer.queue_state) { //now we process our buffers that are ready
			std::vector<uint8> data(buffer_samples);
			int dataLength = GetNextData(data.data(), buffer_samples);
			if (dataLength <= 0) return;
			alBufferData(buffer.buffer_id, format, data.data(), dataLength, rate);
			alSourceQueueBuffers(audio_source.source, 1, &buffer.buffer_id);
			buffer.queue_state = true;
		}
	}
}

//we stop the source to get rid of the playing sounds
void AudioPlayer::Rewind() {
	ResetSource();
	rewind_state = false;
}

bool AudioPlayer::Play() {

	if (rewind_state) Rewind(); //We have to restart the sound here

	FillBuffers();
	ALint state;

	//Get relevant source info 
	alGetSourcei(audio_source.source, AL_SOURCE_STATE, &state);

	//Make sure the source hasn't underrun 
	if (state != AL_PLAYING && state != AL_PAUSED)
	{
		ALint queued;

		//If no buffers are queued, playback is finished 
		alGetSourcei(audio_source.source, AL_BUFFERS_QUEUED, &queued);
		if (queued == 0) return false; //End playing

		alSourcePlay(audio_source.source);
	}

	return true; //still has to play some data
}

void AudioPlayer::Stop() {
	is_active = false;
}

//Figure out the OpenAL format for formats we are currently supporting
int AudioPlayer::GetCorrespondingFormat(bool stereo, bool isSixteenBit) const {
	return stereo ? isSixteenBit ? AL_FORMAT_STEREO16 : AL_FORMAT_STEREO8 :
		            isSixteenBit ? AL_FORMAT_MONO16 : AL_FORMAT_MONO8;
}

bool AudioPlayer::SetUpALSourceIdle() const {
	alSourcef(audio_source.source, AL_MAX_GAIN, OpenALManager::Get()->GetComputedVolume(filterable));
	alSourcef(audio_source.source, AL_GAIN, volume ? volume * OpenALManager::Get()->GetComputedVolume(filterable) : OpenALManager::Get()->GetComputedVolume(filterable));
	return true;
}

bool AudioPlayer::SetUpALSourceInit() const {
	alSourcei(audio_source.source, AL_MIN_GAIN, 0);
	alSourcei(audio_source.source, AL_PITCH, 1);
	alSourcei(audio_source.source, AL_SOURCE_RELATIVE, AL_TRUE);
	alSource3i(audio_source.source, AL_POSITION, 0, 0, 0);
	alSourcei(audio_source.source, AL_ROLLOFF_FACTOR, 0);
	alSource3i(audio_source.source, AL_DIRECTION, 0, 0, 0);
	alSourcei(audio_source.source, AL_DISTANCE_MODEL, AL_NONE);
	alSourcei(audio_source.source, AL_REFERENCE_DISTANCE, 0);
	alSourcei(audio_source.source, AL_MAX_DISTANCE, 0);
	return true;
}
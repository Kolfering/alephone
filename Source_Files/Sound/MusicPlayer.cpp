#include "MusicPlayer.h"
#include "OpenALManager.h"

std::atomic<float> MusicPlayer::default_volume = { 1 };
MusicPlayer::MusicPlayer(std::shared_ptr<StreamDecoder> decoder, MusicParameters parameters) : AudioPlayer(decoder->Rate(), decoder->IsStereo(), decoder->IsSixteenBit()) {
	this->decoder = decoder;
	this->parameters = parameters;
	this->volume = parameters.volume;
	this->decoder->Rewind();
}

int MusicPlayer::GetNextData(uint8* data, int length) {
	int dataSize = decoder->Decode(data, length);
	if (dataSize == length || !parameters.loop) return dataSize;
	decoder->Rewind();
	return dataSize + GetNextData(data + dataSize, length - dataSize);
}

bool MusicPlayer::SetUpALSourceIdle() const {
	float default_music_volume = default_volume.load();
	float music_volume = volume.load();
	alSourcef(audio_source->source_id, AL_MAX_GAIN, default_music_volume * OpenALManager::Get()->GetComputedVolume(filterable));
	alSourcef(audio_source->source_id, AL_GAIN, default_music_volume * music_volume * OpenALManager::Get()->GetComputedVolume(filterable));
	return true;
}
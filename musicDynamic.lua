Triggers = {}
defaultMusic = nil
lastShootTime = 0
presetDefault = nil
presetFight = nil
presetDeath = nil
defaultMode = true

function Triggers.projectile_created(projectile)
	if projectile.owner == Players[0].monster then
	
		if defaultMode == true then
			defaultMusic:request_transition(presetFight)
			defaultMode = false
		end
		lastShootTime = Game.ticks
	end
end

function Triggers.idle()
	if Game.ticks - lastShootTime > 100 and defaultMode == false then 
		 defaultMusic:request_transition(presetDefault)
		 defaultMode = true
	end
	
	
end

function Triggers.player_killed(player, aggressor_player, action, projectile)
	defaultMusic:request_transition(presetDeath)
	defaultMode = true
end

function Triggers.init()
	
		Music.stop()
		
		defaultMusic = Music.new(1, true)
		
		local track1 = defaultMusic:load_track("Glider Pro Sample1.flac")
		local track2 = defaultMusic:load_track("Glider Pro Sample2.flac")
		local track3 = defaultMusic:load_track("Glider Pro Sample3.flac")
		
		presetDefault = defaultMusic:add_preset()
		presetFight = defaultMusic:add_preset()
		presetDeath = defaultMusic:add_preset()
		
		local defaultSegment = presetDefault:add_segment(track1)
		local fightSegment1 = presetFight:add_segment(track2)
		local deathSegment = presetDeath:add_segment(track3)
		
		fightSegment1:map_segment_transition(defaultSegment)
		fightSegment1:map_segment_transition(deathSegment, "sinusoidal", 4, "sinusoidal", 8, true)
		
		
		defaultSegment:map_segment_transition(fightSegment1, "none", 2, "none", 2, true)
		defaultSegment:map_segment_transition(deathSegment, "sinusoidal", 4, "sinusoidal", 8, true)

		defaultMusic:play(defaultSegment)

		--Music.clear()
		--Music[1]:stop()
		
	   local items = { "pistol ammo", "fusion pistol ammo", "assault rifle ammo", "assault rifle grenades", "missile launcher ammo", "alien weapon ammo", "flamethrower ammo", "shotgun ammo", "smg ammo" }
	   for _, item in pairs(items) do
		  Players[0].items[item] = Players[0].items[item] + 10
	   end
	   
		  local weapons = { "alien weapon", "pistol", "fusion pistol", "assault rifle", "missile launcher", "flamethrower", "shotgun", "shotgun", "smg" }
	   for _, weapon in pairs(weapons) do
		  Players[0].items[weapon] = Players[0].items[weapon] + 1
	   end

	   if Players[0].life < 450 then 
		  Players[0].life = 450
	   end
end
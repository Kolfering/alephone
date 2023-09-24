/*
LUA_MNEMONICS.H

	Copyright (C) 2008 by Gregory Smith
 
	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	This license is contained in the file "COPYING",
	which is included with this source code; it is available online at
	http://www.gnu.org/licenses/gpl.html

	Implements the Lua string mnemonics
*/

#include "lua_script.h"

struct lang_def
{
	const char *name;
	int32 value;
};

const lang_def Lua_AmbientSound_Mnemonics[] = {
	{"water", 0},
	{"sewage", 1},
	{"lava", 2},
	{"goo", 3},
	{"underwater", 4},
	{"wind", 5},
	{"waterfall", 6},
	{"siren", 7},
	{"fan", 8},
	{"spht door", 9},
	{"spht platform", 10},
	{"heavy spht door", 11},
	{"heavy spht platform", 12},
	{"light machinery", 13},
	{"heavy machinery", 14},
	{"transformer", 15},
	{"sparking transformer", 16},
	{"machine binder", 17},
	{"machine bookpress", 18},
	{"machine puncher", 19},
	{"electric hum", 20},
	{"alarm", 21},
	{"night wind", 22},
	{"pfhor door", 23},
	{"pfhor platform", 24},
	{"alien noise 1", 25},
	{"alien noise 2", 26},
	{"alien harmonics", 27},
	{0, 0}
};

const lang_def Lua_Collection_Mnemonics[] = {
	{"interface", 0},
	{"weapons in hand", 1},
	{"juggernaut", 2},
	{"tick", 3},
	{"explosions", 4},
	{"hunter", 5},
	{"player", 6},
	{"items", 7},
	{"trooper", 8},
	{"fighter", 9},
	{"defender", 10},
	{"yeti", 11},
	{"bob", 12},
	{"vacbob", 13},
	{"enforcer", 14},
	{"drone", 15},
	{"compiler", 16},
	{"water", 17},
	{"lava", 18},
	{"sewage", 19},
	{"jjaro", 20},
	{"pfhor", 21},
	{"water scenery", 22},
	{"lava scenery", 23},
	{"sewage scenery", 24},
	{"jjaro scenery", 25},
	{"pfhor scenery", 26},
	{"day", 27},
	{"night", 28},
	{"moon", 29},
	{"space", 30},
	{"cyborg", 31},
	{0, 0}
};

const lang_def Lua_CompletionState_Mnemonics[] = {
	{"unfinished", 0},
	{"finished", 1},
	{"failed", 2},
	{0, 0}
};

const lang_def Lua_ControlPanelClass_Mnemonics[] = {
	{"oxygen recharger", 0},
	{"single shield recharger", 1},
	{"double shield recharger", 2},
	{"triple shield recharger", 3},
	{"light switch", 4},
	{"platform switch", 5},
	{"tag switch", 6},
	{"pattern buffer", 7},
	{"terminal", 8},
	{0, 0}
};

const lang_def Lua_DamageType_Mnemonics[] = {
	{"explosion", 0x00},
	{"staff", 0x01},
	{"projectile", 0x02},
	{"absorbed", 0x03},
	{"flame", 0x04},
	{"claws", 0x05},
	{"alien weapon", 0x06},
	{"hulk slap", 0x07},
	{"compiler", 0x08},
	{"fusion", 0x09},
	{"hunter", 0x0A},
	{"fists", 0x0B},
	{"teleporter", 0x0C},
	{"defender", 0x0D},
	{"yeti claws", 0x0E},
	{"yeti projectile", 0x0F},
	{"crushing", 0x10},
	{"lava", 0x11},
	{"suffocation", 0x12},
	{"goo", 0x13},
	{"energy drain", 0x14},
	{"oxygen drain", 0x15},
	{"drone", 0x16},
	{"shotgun", 0x17},
	{0, 0}
};

const lang_def Lua_DifficultyType_Mnemonics[] = {
	{"kindergarten", 0},
	{"easy", 1},
	{"normal", 2},
	{"major damage", 3},
	{"total carnage", 4},
	{0, 0}
};

const lang_def Lua_EffectType_Mnemonics[] = {
	{"rocket explosion", 0},
	{"rocket contrail", 1},
	{"grenade explosion", 2},
	{"grenade contrail", 3},
	{"bullet ricochet", 4},
	{"alien weapon ricochet", 5},
	{"flamethrower burst", 6},
	{"fighter blood splash", 7},
	{"player blood splash", 8},
	{"civilian blood splash", 9},
	{"assimilated civilian blood splash", 10},
	{"enforcer blood splash", 11},
	{"compiler bolt minor detonation", 12},
	{"compiler bolt major detonation", 13},
	{"compiler bolt major contrail", 14},
	{"fighter projectile detonation", 15},
	{"fighter melee detonation", 16},
	{"hunter projectile detonation", 17},
	{"hunter spark", 18},
	{"minor fusion detonation", 19},
	{"major fusion detonation", 20},
	{"major fusion contrail", 21},
	{"fist detonation", 22},
	{"minor defender detonation", 23},
	{"major defender detonation", 24},
	{"defender spark", 25},
	{"trooper blood splash", 26},
	{"water lamp breaking", 27},
	{"lava lamp breaking", 28},
	{"sewage lamp breaking", 29},
	{"alien lamp breaking", 30},
	{"metallic clang", 31},
	{"teleport object in", 32},
	{"teleport object out", 33},
	{"small water splash", 34},
	{"medium water splash", 35},
	{"large water splash", 36},
	{"large water emergence", 37},
	{"small lava splash", 38},
	{"medium lava splash", 39},
	{"large lava splash", 40},
	{"large lava emergence", 41},
	{"small sewage splash", 42},
	{"medium sewage splash", 43},
	{"large sewage splash", 44},
	{"large sewage emergence", 45},
	{"small goo splash", 46},
	{"medium goo splash", 47},
	{"large goo splash", 48},
	{"large goo emergence", 49},
	{"minor hummer projectile detonation", 50},
	{"major hummer projectile detonation", 51},
	{"durandal hummer projectile detonation", 52},
	{"hummer spark", 53},
	{"cyborg projectile detonation", 54},
	{"cyborg blood splash", 55},
	{"minor fusion dispersal", 56},
	{"major fusion dispersal", 57},
	{"overloaded fusion dispersal", 58},
	{"sewage yeti blood splash", 59},
	{"sewage yeti projectile detonation", 60},
	{"water yeti blood splash", 61},
	{"lava yeti blood splash", 62},
	{"lava yeti projectile detonation", 63},
	{"yeti melee detonation", 64},
	{"juggernaut spark", 65},
	{"juggernaut missile contrail", 66},
	{"small jjaro splash", 67},
	{"medium jjaro splash", 68},
	{"large jjaro splash", 69},
	{"large jjaro emergence", 70},
	{"civilian fusion blood splash", 71},
	{"assimilated civilian fusion blood splash", 72},
	{0, 0}
};

const lang_def Lua_FadeType_Mnemonics[] = {
	{"start cinematic fade in", 0x0},
	{"cinematic fade in", 0x1},
	{"long cinematic fade in", 0x2},
	{"cinematic fade out", 0x3},
	{"end cinematic fade out", 0x4},
	{"red", 0x05},
	{"big red", 0x06},
	{"bonus", 0x07},
	{"bright", 0x08},
	{"long bright", 0x09},
	{"yellow", 0x0A},
	{"big yellow", 0x0B},
	{"purple", 0x0C},
	{"cyan", 0x0D},
	{"white", 0x0E},
	{"big white", 0x0F},
	{"orange", 0x10},
	{"long orange", 0x11},
	{"green", 0x12},
	{"long green", 0x13},
	{"static", 0x14},
	{"negative", 0x15},
	{"big negative", 0x16},
	{"flicker negative", 0x17},
	{"dodge purple", 0x18},
	{"burn cyan", 0x19},
	{"dodge yellow", 0x1A},
	{"burn green", 0x1B},
	{"tint green", 0x1C},
	{"tint blue", 0x1D},
	{"tint orange", 0x1E},
	{"tint gross", 0x1F},
	{"tint jjaro", 0x20},
	{0, 0}
};

const lang_def Lua_FogMode_Mnemonics[] = {
	{"linear", 0},
	{"exp", 1},
	{"exp2", 2},
	{0, 0}
};

const lang_def Lua_GameType_Mnemonics[] = {
	{"kill monsters", 0x00},
	{"cooperative play", 0x01},
	{"capture the flag", 0x02},
	{"king of the hill", 0x03},
	{"kill the man with the ball", 0x04},
	{"defense", 0x05},
	{"rugby", 0x06},
	{"tag", 0x07},
	{"netscript", 0x08},
	{0, 0}
};

const lang_def Lua_ScoringMode_Mnemonics[] = {
  {"most points", _game_of_most_points},
  {"most time", _game_of_most_time},
  {"least points", _game_of_least_points},
  {"least time", _game_of_least_time},
  {0, 0}
};

const lang_def Lua_ItemKind_Mnemonics[] = {
	{"weapon", 0},
	{"ammunition", 1},
	{"powerup", 2},
	{"item", 3},
	{"weapon_powerup", 4},
	{"ball", 5},
	{0, 0}
};

const lang_def Lua_ItemType_Mnemonics[] = {
	{"knife", 0},
	{"pistol", 1},
	{"pistol ammo", 2},
	{"fusion pistol", 3},
	{"fusion pistol ammo", 4},
	{"assault rifle", 5},
	{"assault rifle ammo", 6},
	{"assault rifle grenades", 7},
	{"missile launcher", 8},
	{"missile launcher ammo", 9},
	{"invisibility", 10},
	{"invincibility", 11},
	{"infravision", 12},
	{"alien weapon", 13},
	{"alien weapon ammo", 14},
	{"flamethrower", 15},
	{"flamethrower ammo", 16},
	{"extravision", 17},
	{"oxygen", 18},
	{"single health", 19},
	{"double health", 20},
	{"triple health", 21},
	{"shotgun", 22},
	{"shotgun ammo", 23},
	{"key", 24},
	{"uplink chip", 25},
	{"light blue ball", 26},
	{"ball", 27},
	{"violet ball", 28},
	{"yellow ball", 29},
	{"brown ball", 30},
	{"orange ball", 31},
	{"blue ball", 32},
	{"green ball", 33},
	{"smg", 34},
	{"smg ammo", 35},
	{0, 0}
};

const lang_def Lua_EphemeraQuality_Mnemonics[] = {
	{"off", 0},
	{"low", 1},
	{"medium", 2},
	{"high", 3},
	{"ultra", 4},
        {0, 0}
};

const lang_def Lua_LightFunction_Mnenonics[] = {
	{"constant", 0},
	{"linear", 1},
	{"smooth", 2},
	{"flicker", 3},
	{0, 0}
};

const lang_def Lua_LightPreset_Mnemonics[] = {
	{"normal", 0},
	{"strobe", 1},
	{"media", 2},
	{0, 0}
};

const lang_def Lua_LightState_Mnemonics[] = {
	{"becoming active", 0},
	{"primary active", 1},
	{"secondary active", 2},
	{"becoming inactive", 3},
	{"primary inactive", 4},
	{"secondary inactive", 5},
	{0, 0}
};

const lang_def Lua_MediaType_Mnemonics[] = {
	{"water", 0},
	{"lava", 1},
	{"goo", 2},
	{"sewage", 3},
	{"jjaro", 4},
	{0, 0}
};

const lang_def Lua_MonsterClass_Mnemonics[] = {
	{"player", 0x0001},
	{"bob", 0x0002},
	{"madd", 0x0004},
	{"possessed drone", 0x0008},
	{"defender", 0x0010},
	{"fighter", 0x0020},
	{"trooper", 0x0040},
	{"hunter", 0x0080},
	{"enforcer", 0x0100},
	{"juggernaut", 0x0200},
	{"drone", 0x0400},
	{"compiler", 0x0800},
	{"cyborg", 0x1000},
	{"explodabob", 0x2000},
	{"tick", 0x4000},
	{"yeti", 0x8000},
	{0, 0}
};

const lang_def Lua_MonsterAction_Mnemonics[] = {
	{"stationary", 0x00},
	{"waiting to attack again", 0x01},
	{"moving", 0x02},
	{"attacking close", 0x03},
	{"attacking far", 0x04},
	{"being hit", 0x05},
	{"dying hard", 0x06},
	{"dying soft", 0x07},
	{"dying flaming", 0x08},
	{"teleporting", 0x09},
	{"teleporting in", 0x0A},
	{"teleporting out", 0x0B},
	{0, 0}
};

const lang_def Lua_MonsterMode_Mnemonics[] = {
	{"locked", 0},
	{"losing lock", 1},
	{"lost lock", 2},
	{"unlocked", 3},
	{"running", 4},
	{0, 0}
};

const lang_def Lua_MonsterType_Mnemonics[] = {
	{"player", 0x00},
	{"minor tick", 0x01},
	{"major tick", 0x02},
	{"kamikaze tick", 0x03},
	{"minor compiler", 0x04},
	{"major compiler", 0x05},
	{"minor invisible compiler", 0x06},
	{"major invisible compiler", 0x07},
	{"minor fighter", 0x08},
	{"major fighter", 0x09},
	{"minor projectile fighter", 0x0A},
	{"major projectile fighter", 0x0B},
	{"green bob", 0x0C},
	{"blue bob", 0x0D},
	{"security bob", 0x0E},
	{"explodabob", 0x0F},
	{"minor drone", 0x10},
	{"major drone", 0x11},
	{"big minor drone", 0x12},
	{"big major drone", 0x13},
	{"possessed drone", 0x14},
	{"minor cyborg", 0x15},
	{"major cyborg", 0x16},
	{"minor flame cyborg", 0x17},
	{"major flame cyborg", 0x18},
	{"minor enforcer", 0x19},
	{"major enforcer", 0x1A},
	{"minor hunter", 0x1B},
	{"major hunter", 0x1C},
	{"minor trooper", 0x1D},
	{"major trooper", 0x1E},
	{"mother of all cyborgs", 0x1F},
	{"mother of all hunters", 0x20},
	{"sewage yeti", 0x21},
	{"water yeti", 0x22},
	{"lava yeti", 0x23},
	{"minor defender", 0x24},
	{"major defender", 0x25},
	{"minor juggernaut", 0x26},
	{"major juggernaut", 0x27},
	{"tiny pfhor", 0x28},
	{"tiny bob", 0x29},
	{"tiny yeti", 0x2A},
	{"green vacbob", 0x2B},
	{"blue vacbob", 0x2C},
	{"security vacbob", 0x2D},
	{"explodavacbob", 0x2E},
	{0, 0}
};

const lang_def Lua_OverlayColor_Mnemonics[] = {
	{"green", 0},
	{"white", 1},
	{"red", 2},
	{"dark green", 3},
	{"cyan", 4},
	{"yellow", 5},
	{"dark red", 6},
	{"blue", 7},
	{0, 0}
};

const lang_def Lua_PlatformType_Mnemonics[] = {
	{"spht door", 0},
	{"spht split door", 1},
	{"locked spht door", 2},
	{"spht platform", 3},
	{"noisy spht platform", 4},
	{"heavy spht door", 5},
	{"pfhor door", 6},
	{"heavy spht platform", 7},
	{"pfhor platform", 8},
	{0, 0}
};

const lang_def Lua_PlayerColor_Mnemonics[] = {
	{"slate", 0},
	{"red", 1},
	{"violet", 2},
	{"yellow", 3},
	{"white", 4},
	{"orange", 5},
	{"blue", 6},
	{"green", 7},
	{0, 0}
};

const lang_def Lua_PolygonType_Mnemonics[] = {
	{"normal", 0x00},
	{"item impassable", 0x01},
	{"monster impassable", 0x02},
	{"hill", 0x03},
	{"base", 0x04},
	{"platform", 0x05},
	{"light on trigger", 0x06},
	{"platform on trigger", 0x07},
	{"light off trigger", 0x08},
	{"platform off trigger", 0x09},
	{"teleporter", 0x0A},
	{"zone border", 0x0B},
	{"goal", 0x0C},
	{"visible monster trigger", 0x0D},
	{"invisible monster trigger", 0x0E},
	{"dual monster trigger", 0x0F},
	{"item trigger", 0x10},
	{"must be explored", 0x11},
	{"automatic exit", 0x12},
	{"minor ouch", 0x13},
	{"major ouch", 0x14},
	{"glue", 0x15},
	{"glue trigger", 0x16},
	{"superglue", 0x17},
	{0, 0}
};

const lang_def Lua_ProjectileType_Mnemonics[] = {
	{"missile", 0x00},
	{"grenade", 0x01},
	{"pistol bullet", 0x02},
	{"rifle bullet", 0x03},
	{"shotgun bullet", 0x04},
	{"staff", 0x05},
	{"staff bolt", 0x06},
	{"flamethrower burst", 0x07},
	{"compiler bolt minor", 0x08},
	{"compiler bolt major", 0x09},
	{"alien weapon", 0x0A},
	{"fusion bolt minor", 0x0B},
	{"fusion bolt major", 0x0C},
	{"hunter", 0x0D},
	{"fist", 0x0E},
	{"armageddon sphere", 0x0F},
	{"armageddon electricity", 0x10},
	{"juggernaut rocket", 0x11},
	{"trooper bullet", 0x12},
	{"trooper grenade", 0x13},
	{"minor defender", 0x14},
	{"major defender", 0x15},
	{"juggernaut missile", 0x16},
	{"minor energy drain", 0x17},
	{"major energy drain", 0x18},
	{"oxygen drain", 0x19},
	{"minor hummer", 0x1A},
	{"major hummer", 0x1B},
	{"durandal hummer", 0x1C},
	{"minor cyborg ball", 0x1D},
	{"major cyborg ball", 0x1E},
	{"ball", 0x1F},
	{"minor fusion dispersal", 0x20},
	{"major fusion dispersal", 0x21},
	{"overloaded fusion dispersal", 0x22},
	{"yeti", 0x23},
	{"sewage yeti", 0x24},
	{"lava yeti", 0x25},
	{"smg bullet", 0x26},
	{0, 0}
};

const lang_def Lua_SceneryType_Mnemonics[] = {
	{"light dirt", 0},
	{"dark dirt", 1},
	{"lava bones", 2},
	{"lava bone", 3},
	{"ribs", 4},
	{"skull", 5},
	{"hanging light 1", 6},
	{"hanging light 2", 7},
	{"small cylinder", 8},
	{"large cylinder", 9},
	{"block 1", 10},
	{"block 2", 11},
	{"block 3", 12},

	{"pistol clip", 13},
	{"water short light", 14},
	{"water long light", 15},
	{"siren", 16},
	{"rocks", 17},
	{"blood drops", 18},
	{"water thing", 19},
	{"gun", 20},
	{"bob remains", 21},
	{"puddles", 22},
	{"big puddles", 23},
	{"security monitor", 24},
	{"water alien supply can", 25},
	{"machine", 26},
	{"staff", 27},
	
	{"sewage short light", 28},
	{"sewage long light", 29},
	{"junk", 30},
	{"antenna", 31},
	{"big antenna", 32},
	{"sewage alien supply can", 33},
	{"sewage bones", 34},
	{"sewage big bones", 35},
	{"pfhor pieces", 36},
	{"bob pieces", 37},
	{"bob blood", 38},
	
	{"alien short light", 39},
	{"alien long light", 40},
	{"alien ceiling rod light", 41},
	{"bulbous yellow alien object", 42},
	{"square gray organic object", 43},
	{"pfhor skeleton", 44},
	{"pfhor mask", 45},
	{"green stuff", 46},
	{"hunter shield", 47},
	{"alien bones", 48},
	{"alien sludge", 49},

	{"jjaro short light", 50},
	{"jjaro long light", 51},
	{"weird rod", 52},
	{"pfhor ship", 53},
	{"sun", 54},
	{"large glass container", 55},
	{"nub 1", 56},
	{"nub 2", 57},
	{"lh'owon", 58},
	{"floor whip antenna", 59},
	{"ceiling whip antenna", 60},
	{0, 0}
};

const lang_def Lua_SideType_Mnemonics[] = {
	{"full", 0},
	{"high", 1},
	{"low", 2},
	{"split", 4},
	{0, 0}
};

const lang_def Lua_SizePref_Mnemonics[] = {
{"normal", 0},
{"double", 1},
{"largest", 2},
{0, 0}
};

const lang_def Lua_Sound_Mnemonics[] = {
	{"startup", 0},
	{"teleport in", 1},
	{"teleport out", 2},
	{"crushed", 3},
	{"nuclear hard death", 4},
	{"absorbed", 5},
	{"breathing", 6},
	{"oxygen warning", 7},
	{"suffocation", 8},
	{"energy refuel", 9},
	{"oxygen refuel", 10},
	{"cant toggle switch", 11},
	{"switch on", 12},
	{"switch off", 13},
	{"puzzle switch", 14},
	{"chip insertion", 15},
	{"pattern buffer", 16},
	{"destroy control panel", 17},
	{"adjust volume", 18},
	{"got powerup", 19},
	{"get item", 20},
	{"bullet ricochet", 21},
	{"metallic ricochet", 22},
	{"empty gun", 23},
	{"spht door opening", 24},
	{"spht door closing", 25},
	{"spht door obstructed", 26},
	{"spht platform starting", 27},
	{"spht platform stopping", 28},
	{"loon", 29},
	{"smg firing", 30},
	{"smg reloading", 31},
	{"heavy spht platform starting", 32},
	{"heavy spht platform stopping", 33},
	{"fist hitting", 34},
	{"pistol firing", 35},
	{"pistol reloading", 36},
	{"assault rifle firing", 37},
	{"grenade launcher firing", 38},
	{"grenade expolding", 39},
	{"grenade flyby", 40},
	{"fusion firing", 41},
	{"fusion exploding", 42},
	{"fusion flyby", 43},
	{"fusion charging", 44},
	{"rocket exploding", 45},
	{"rocket flyby", 46},
	{"rocket firing", 47},
	{"flamethrower", 48},
	{"body falling", 49},
	{"body exploding", 50},
	{"bullet hit flesh", 51},
	{"fighter activate", 52},
	{"fighter wail", 53},
	{"fighter scream", 54},
	{"fighter chatter", 55},
	{"fighter attack", 56},
	{"fighter projectile hit", 57},
	{"fighter projectile flyby", 58},
	{"spht attack", 59},
	{"spht death", 60},
	{"spht hit", 61},
	{"spht projectile flyby", 62},
	{"spht projectile hit", 63},
	{"cyborg moving", 64},
	{"cyborg attack", 65},
	{"cyborg hit", 66},
	{"cyborg death", 67},
	{"cyborg projectile bounce", 68},
	{"cyborg projectile hit", 69},
	{"cyborg projectile flyby", 70},
	{"drone activate", 71},
	{"drone start attack", 72},
	{"drone attack", 73},
	{"drone dying", 74},
	{"drone death", 75},
	{"drone projectile hit", 76},
	{"drone projectile flyby", 77},
	{"bob wail", 78},
	{"bob scream", 79},
	{"bob hit", 80},
	{"bob chatter", 81},
	{"assimilated bob chatter", 82},
	{"bob trash talk", 83},
	{"bob apology", 84},
	{"bob activation", 85},
	{"bob clear", 86},
	{"bob angry", 87},
	{"bob secure", 88},
	{"bob kill the player", 89},
	{"water", 90},
	{"sewage", 91},
	{"lava", 92},
	{"goo", 93},
	{"underwater", 94},
	{"wind", 95},
	{"waterfall", 96},
	{"siren", 97},
	{"fan", 98},
	{"spht door", 99},
	{"spht platform", 100},
	{"alien harmonics", 101},
	{"heavy spht platform", 102},
	{"light machinery", 103},
	{"heavy machinery", 104},
	{"transformer", 105},
	{"sparking transformer", 106},
	{"water drip", 107},
	{"walking in water", 108},
	{"exiting water", 109},
	{"entering water", 110},
	{"small water splash", 111},
	{"medium water splash", 112},
	{"large water splash", 113},
	{"walking in lava", 114},
	{"entering lava", 115},
	{"exiting lava", 116},
	{"small lava splash", 117},
	{"medium lava splash", 118},
	{"large lava splash", 119},
	{"walking in sewage", 120},
	{"exiting sewage", 121},
	{"entering sewage", 122},
	{"small sewage splash", 123},
	{"medium sewage splash", 124},
	{"large sewage splash", 125},
	{"walking in goo", 126},
	{"exiting goo", 127},
	{"entering goo", 128},
	{"small goo splash", 129},
	{"medium goo splash", 130},
	{"large goo splash", 131},
	{"major fusion firing", 132},
	{"major fusion charged", 133},
	{"assault rifle reloading", 134},
	{"assault rifle shell casings", 135},
	{"shotgun firing", 136},
	{"shotgun reloading", 137},
	{"ball bounce", 138},
	{"you are it", 139},
	{"got ball", 140},
	{"computer login", 141},
	{"computer logout", 142},
	{"computer page", 143},
	{"heavy shpt door", 144},
	{"heavy spht door", 144},
	{"heavy spht door opening", 145},
	{"heavy spht door closing", 146},
	{"heavy spht door open", 147},
	{"heavy spht door closed", 148},
	{"heavy spht door obstructed", 149},
	{"hunter activate", 150},
	{"hunter attack", 151},
	{"hunter dying", 152},
	{"hunter landing", 153},
	{"hunter exploding", 154},
	{"hunter projectile hit", 155},
	{"hunter projectile flyby", 156},
	{"enforcer activate", 157},
	{"enforcer attack", 158},
	{"enforcer projectile hit", 159},
	{"enforcer projectile flyby", 160},
	{"flickta melee attack", 161},
	{"flickta melee hit", 162},
	{"flickta projectile attack", 163},
	{"flickta projectile sewage hit", 164},
	{"flickta projectile sewage flyby", 165},
	{"flickta projectile lava hit", 166},
	{"flickta projectile lava flyby", 167},
	{"flickta dying", 168},
	{"machine binder", 169},
	{"machine bookpress", 170},
	{"machine puncher", 171},
	{"electric hum", 172},
	{"alarm", 173},
	{"night wind", 174},
	{"surface explosion", 175},
	{"underground explosion", 176},
	{"sphtkr attack", 177},
	{"sphtkr projectile hit", 178},
	{"sphtkr projectile flyby", 179},
	{"sphtkr hit", 180},
	{"sphtkr exploding", 181},
	{"tick chatter", 182},
	{"tick falling", 183},
	{"tick flapping", 184},
	{"tick exploding", 185},
	{"ceiling lamp exploding", 186},
	{"pfhor platform starting", 187},
	{"pfhor platform stopping", 188},
	{"pfhor platform", 189},
	{"pfhor door opening", 190},
	{"pfhor door closing", 191},
	{"pfhor door obstructed", 192},
	{"pfhor door", 193},
	{"pfhor switch off", 194},
	{"pfhor switch on", 195},
	{"juggernaut firing", 196},
	{"juggernaut warning", 197},
	{"juggernaut exploding", 198},
	{"juggernaut start attack", 199},
	{"enforcer exploding", 200},
	{"alien noise 1", 201},
	{"alien noise 2", 202},
	{"vacbob wail", 203},
	{"vacbob scream", 204},
	{"vacbob hit", 205},
	{"vacbob chatter", 206},
	{"assimilated vacbob chatter", 207},
	{"vacbob trash talk", 208},
	{"vacbob apology", 209},
	{"vacbob activation", 210},
	{"vacbob clear", 211},
	{"vacbob angry", 212},
	{"vacbob secure", 213},
	{"vacbob kill the player", 214},
	{0, 0}
};

const lang_def Lua_TransferMode_Mnemonics[] = {
	{"normal", 0},
	{"pulsate", 4},
	{"wobble", 5},
	{"fast wobble", 6},
	{"static", 7},
	{"landscape", 9},
	{"horizontal slide", 15},
	{"fast horizontal slide", 16},
	{"vertical slide", 17},
	{"fast vertical slide", 18},
	{"wander", 19},
	{"fast wander", 20},
	{0, 0}
};

const lang_def Lua_WeaponType_Mnemonics[] = {
	{"fist", 0},
	{"pistol", 1},
	{"fusion pistol", 2},
	{"assault rifle", 3},
	{"missile launcher", 4},
	{"flamethrower", 5},
	{"alien weapon", 6},
	{"shotgun", 7},
	{"ball", 8},
	{"smg", 9},
	{0, 0}
};

const lang_def Lua_InventorySection_Mnemonics[] = {
{"weapons", 0},
{"ammunition", 1},
{"powerups", 2},
{"items", 3},
{"weapon powerups", 4},
{"balls", 5},
{"network statistics", 6},
{0, 0}
};

const lang_def Lua_RendererType_Mnemonics[] = {
{"opengl", 1},
{"software", 0},
{"shader", 2},
{0, 0}
};

const lang_def Lua_SensorBlipType_Mnemonics[] = {
{"friend", 0},
{"alien", 1},
{"hostile player", 2},
{0, 0}
};

const lang_def Lua_FadeEffectType_Mnemonics[] = {
{"tint", 0},
{"randomize", 1},
{"negate", 2},
{"dodge", 3},
{"burn", 4},
{"soft tint", 5},
{0, 0}
};

const lang_def Lua_MaskingMode_Mnemonics[] = {
{"disabled", 0},
{"enabled", 1},
{"drawing", 2},
{"erasing", 3},
{0, 0}
};

const lang_def Lua_TextureType_Mnemonics[] = {
{"wall", 0},
{"landscape", 1},
{"sprite", 2},
{"weapon in hand", 3},
{"interface", 4},
{0, 0}
};

const lang_def Lua_InterfaceColor_Mnemonics[] = {
{"ammo box full", 0},
{"ammo box empty", 1},
{"black", 2},
{"inventory text", 3},
{"inventory header background", 4},
{"inventory background", 5},
{"slate player", 6},
{"red player", 7},
{"violet player", 8},
{"yellow player", 9},
{"white player", 10},
{"orange player", 11},
{"blue player", 12},
{"green player", 13},
{"white", 14},
{"invalid weapon", 15},
{"computer border text background", 16},
{"computer border text", 17},
{"computer text", 18},
{"computer white text", 19},
{"computer red text", 20},
{"computer dark green text", 21},
{"computer cyan text", 22},
{"computer yellow text", 23},
{"computer dark red text", 24},
{"computer blue text", 25},
{0, 0}
};

const lang_def Lua_InterfaceFont_Mnemonics[] = {
{"interface", 0},
{"weapon name", 1},
{"player name", 2},
{"interface item count", 3},
{"terminal", 4},
{"terminal title", 5},
{"network statistics", 6},
{0, 0}
};

const lang_def Lua_InterfaceRect_Mnemonics[] = {
{"player name", 0},
{"oxygen", 1},
{"shield", 2},
{"motion sensor", 3},
{"microphone", 4},
{"inventory", 5},
{"weapon display", 6},
{"new-game button", 7},
{"load-game button", 8},
{"gather button", 9},
{"join button", 10},
{"preferences button", 11},
{"replay button", 12},
{"save-last button", 13},
{"replace-saved button", 14},
{"credits button", 15},
{"quit button", 16},
{"center button", 17},
{"unused 18", 18},
{"unused 19", 19},
{"terminal screen", 20},
{"terminal header", 21},
{"terminal footer", 22},
{"terminal full text", 23},
{"terminal left", 24},
{"terminal right", 25},
{"terminal logon graphic", 26},
{"terminal logon title", 27},
{"terminal logon location", 28},
{"respawn indicator", 29},
{"blinker", 30},
{0, 0}
};

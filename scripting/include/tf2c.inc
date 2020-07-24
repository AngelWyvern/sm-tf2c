#if defined _tf2c_included
 #endinput
#endif
#define _tf2c_included

enum TFClassType
{
	TFClass_Unknown  = 0,
	TFClass_Scout    = 1,
	TFClass_Sniper   = 2,
	TFClass_Soldier  = 3,
	TFClass_DemoMan  = 4,
	TFClass_Medic    = 5,
	TFClass_Heavy    = 6,
	TFClass_Pyro     = 7,
	TFClass_Spy      = 8,
	TFClass_Engineer = 9,
	TFClass_Civilian = 10
};

enum TFTeam
{
	TFTeam_Unassigned = 0,
	TFTeam_Spectator  = 1,
	TFTeam_Red        = 2,
	TFTeam_Blue       = 3,
	TFTeam_Green      = 4,
	TFTeam_Yellow     = 5
};

enum TFCond
{
	TFCond_Slowed = 0, //0: Revving Minigun, Sniper Rifle. Gives zoomed/revved pose
	TFCond_Zoomed, //1: Sniper Rifle zooming
	TFCond_Disguising, //2: Disguise smoke
	TFCond_Disguised, //3: Disguise
	TFCond_Cloaked, //4: Cloak effect
	TFCond_Ubercharged, //5: Invulnerability, removed when being healed or by another Uber effect
	TFCond_TeleportedGlow, //6: Teleport trail effect
	TFCond_Taunting, //7: Used for taunting, can remove to stop taunting
	TFCond_UberchargeFading, //8: Invulnerability expiration effect
	TFCond_Unknown1, //9
	TFCond_CloakFlicker = 9, //9: Cloak flickering effect
	TFCond_Teleporting, //10: Used for teleporting, does nothing applying
	TFCond_Kritzkrieged, //11: Crit boost, removed when being healed or another Uber effect
	TFCond_Unknown2, //12
	TFCond_TmpDamageBonus = 12, //12: Temporary damage buff, something along with attribute 19
	TFCond_Dazed = 15, //15: Slow effect, can remove to remove stun effects
	TFCond_Healing = 21, //21: Used for healing, does nothing applying
	TFCond_OnFire, //22: Ignite sound and vocals, can remove to remove afterburn
	TFCond_Overhealed, //23: Used for overheal, does nothing applying
	TFCond_Jarated, //24: Jarate effect
	TFCond_Bleeding, //25: Bleed effect
	TFCond_MarkedForDeath = 30, //30: Fan o' War marked-for-death effect
	TFCond_HalloweenCritCandy = 33, //33: Halloween pumpkin crit-boost
	TFCond_CritCanteen, //34: Crit-boost and doubles Sentry Gun fire-rate
	TFCond_CritDemoCharge, //35: Crit glow, adds TFCond_Charging when charge meter is below 75%
	TFCond_CritOnFirstBlood = 37, //37: Arena first blood crit-boost
	TFCond_CritOnWin, //38: End-of-round crit-boost (May not remove correctly?)
	TFCond_CritOnFlagCapture, //39: Intelligence capture crit-boost
	TFCond_CritOnKill, //40: Crit-boost from crit-on-kill weapons
	TFCond_RestrictToMelee, //41: Prevents switching once melee is out
	TFCond_MarkedForDeathSilent = 48, //48: Marked-for-death without sound effect
	TFCond_DisguisedAsDispenser, //49: Dispenser disguise when crouching, max movement speed, sentries ignore player
	TFCond_UberchargedHidden = 51, //51: Non-visual uber effect, will appear when damage is taken
	TFCond_UberchargedCanteen, //52: Invulnerability effect and Sentry Gun damage resistance
	TFCond_HalloweenBombHead, //53: Bomb head effect (semi-functional, does not explode, bomb is invisible)
	TFCond_CritOnDamage = 56, //56: Miscellaneous crit-boost
	TFCond_UberchargedOnTakeDamage, //57: Miscellaneous invulnerability
	TFCond_Stealthed = 64, //64: Cloaked until next attack (semi-functional, doesn't uncloak)
	TFCond_BulletImmune = 67, //67: Full bullet immunity
	TFCond_BlastImmune, //68: Full blast immunity
	TFCond_FireImmune, //69: Full fire immunity
	TFCond_HalloweenGiant = 74, //74: Double size, x10 max health increase, ammo regeneration, and forced thirdperson
	TFCond_HalloweenTiny, //75: Half size and increased head size
	TFCond_HalloweenGhostMode = 77, //77: Supposed to ghost you, but instead you're just forced in thirdperson
	TFCond_BlastJumping = 81, //81: Player is blast jumping
	TFCond_KnockedIntoAir = 115, //115: Used when a player is airblasted
};

enum TFObjectType
{
	TFObject_CartDispenser = 0,
	TFObject_Dispenser     = 0,
	TFObject_Teleporter    = 1,
	TFObject_Sentry        = 2,
	TFObject_Sapper        = 3
};

enum TFObjectMode
{
	TFObjectMode_None     = 0,
	TFObjectMode_Entrance = 0,
	TFObjectMode_Exit     = 1
};

/**
 * Respawns a client
 *
 * @param client        Player's index.
 * @error               Invalid client index, client not in game, or no mod support.
 */
native void TF2_RespawnPlayer(int client);

/**
 * Gets a client's current class.
 *
 * @param client        Player's index.
 * @return              Current TFClassType of player.
 * @error               Invalid client index.
 */
stock TFClassType TF2_GetPlayerClass(int client)
{
	return view_as<TFClassType>(GetEntProp(client, Prop_Send, "m_iClass"));
}

/**
 * Gets a client's current team.
 *
 * @param client        Client index.
 * @return              Current TFTeam of client.
 * @error               Invalid client index.
 */
stock TFTeam TF2_GetClientTeam(int client)
{
	return view_as<TFTeam>(GetClientTeam(client));
}
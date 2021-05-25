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

const float TFCondDuration_Infinite = -1.0;

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
 * Sets a client on fire for 10 seconds.
 *
 * @param client		Player's index.
 * @param attacker		Attacker's index.
 * @error				Invalid client index, client not in game, or no mod support.
 */
native void TF2_IgnitePlayer(int client, int attacker);

/**
 * Respawns a client
 *
 * @param client        Player's index.
 * @error               Invalid client index, client not in game, or no mod support.
 */
native void TF2_RespawnPlayer(int client);

/**
 * Regenerates a client's health and ammunition
 *
 * @param client        Player's index.
 * @error               Invalid client index, client not in game, or no mod support.
 */
native void TF2_RegeneratePlayer(int client);

/**
 * Adds a condition to a player
 *
 * @param client        Player's index.
 * @param condition     Integer identifier of condition to apply.
 * @param duration      Duration of condition (does not apply to all conditions).
 *                      Pass TFCondDuration_Infinite to apply until manually removed.
 * @param inflictor     Condition inflictor's index (0 for no inflictor).
 * @error               Invalid client index, client not in game, or no mod support.
 */
native void TF2_AddCondition(int client, TFCond condition, float duration=TFCondDuration_Infinite, int inflictor=0);

/**
 * Removes a condition from a player
 *
 * @param client        Player's index.
 * @param condition     Integer identifier of condition to remove.
 * @error               Invalid client index, client not in game, or no mod support.
 */
native void TF2_RemoveCondition(int client, TFCond condition);

/**
 * Disguises a client to the given model and team. Only has an effect on spies.
 *
 * Note: This only starts the disguise process and a delay occurs before the spy is fully disguised
 *
 * @param client        Player's index.
 * @param team          Team to disguise the player as (only TFTeam_Red and TFTeam_Blue have an effect)
 * @param classType     TFClassType class to disguise the player as
 * @param target        Specific target player to disguise as (0 for any)
 * @error               Invalid client index, client not in game, or no mod support.
 */
native void TF2_DisguisePlayer(int client, TFTeam team, TFClassType classType, int target=0);

/**
 * Removes the current disguise from a client. Only has an effect on spies.
 *
 * @param client        Player's index.
 * @error               Invalid client index, client not in game, or no mod support.
 */
native void TF2_RemovePlayerDisguise(int client);

/**
 * Called on weapon fire to decide if the current shot should be critical.
 * Return Plugin_Continue to let the original calculation or return a higher
 * action to override the decision with the value of 'result'
 *
 * @note Since critical shots are also calculated client side any changes made with
 *       this will not show for the shooter. Projectile weapons such as the rocketlauncher
 *       and demoman weapons will show a critical bullet but no critical sound effect.
 *       Bullet hits should appear as expected.
 *
 * @param client        Client Index.
 * @param weapon        Weapon entity Index.
 * @param weaponname    Classname of the weapon.
 * @param result        Buffer param for the result of the decision.
 */
forward Action TF2_CalcIsAttackCritical(int client, int weapon, char[] weaponname, bool &result);

/**
 * Called after a condition is added to a player
 *
 * @param client        Index of the client to which the condition is being added.
 * @param condition     Condition that is being added.
 */
forward void TF2_OnConditionAdded(int client, TFCond condition);

/**
 * Called after a condition is removed from a player
 *
 * @param client        Index of the client to which the condition is being removed.
 * @param condition     Condition that is being removed.
 */
forward void TF2_OnConditionRemoved(int client, TFCond condition);

/**
 * Called when the server enters the Waiting for Players round state
 */
forward void TF2_OnWaitingForPlayersStart();

/**
 * Called when the server exits the Waiting for Players round state
 */
forward void TF2_OnWaitingForPlayersEnd();

/**
 * Called when a player attempts to use a teleporter to decide if the player should be allowed to teleport.
 * Return Plugin_Continue to let the original calculation or return a higher
 * action to override the decision with the value of 'result'
 *
 * @param client        Client index.
 * @param teleporter    Teleporter entity index.
 * @param result        Buffer param for the result of the decision.
 *                      This is prepopulated with the game's original decision to let a player teleport.
 * @return              Plugin_Continue for original calculation, higher value to use 'result'.
 */
forward Action TF2_OnPlayerTeleport(int client, int teleporter, bool &result);

/**
 * Finds the TFClassType for a given class name.
 *
 * @param classname     A classname string such as "sniper" or "demoman"
 * @return              A TFClassType constant.
 */
stock TFClassType TF2_GetClass(const char[] classname)
{
	if (StrEqual(classname, "scout"))
		return TFClass_Scout;
	if (StrEqual(classname, "soldier"))
		return TFClass_Soldier;
	if (StrEqual(classname, "pyro"))
		return TFClass_Pyro;
	if (StrEqual(classname, "demoman"))
		return TFClass_DemoMan;
	if (StrEqual(classname, "heavyweapons"))
		return TFClass_Heavy;
	if (StrEqual(classname, "engineer"))
		return TFClass_Engineer;
	if (StrEqual(classname, "medic"))
		return TFClass_Medic;
	if (StrEqual(classname, "sniper"))
		return TFClass_Sniper;
	if (StrEqual(classname, "spy"))
		return TFClass_Spy;
	if (StrEqual(classname, "civilian"))
		return TFClass_Civilian;
	return TFClass_Unknown;
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

/**
 * Changes a client's current team.
 *
 * @param client        Client index.
 * @param team          TFTeam team symbol.
 * @error               Invalid client index.
 */
stock void TF2_ChangeClientTeam(int client, TFTeam team)
{
	ChangeClientTeam(client, view_as<int>(team));
}

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
 * Sets a client's class.
 *
 * Note: If setting player class in a player spawn hook weapons should be set to false.
 *
 * @param client        Player's index.
 * @param classType     TFClassType class symbol.
 * @param weapons       This parameter is ignored.
 * @param persistent    If true, changes the player's desired class so the change stays after death.
 * @error               Invalid client index.
 */
stock void TF2_SetPlayerClass(int client, TFClassType classType, bool weapons=true, bool persistent=true)
{
	SetEntProp(client, Prop_Send, "m_iClass", view_as<int>(classType));

	if (persistent)
	{
		SetEntProp(client, Prop_Send, "m_iDesiredPlayerClass", view_as<int>(classType));
	}
}

/**
 * Retrieves client data from the resource entity
 *
 * @param client		Player's index.
 * @param type			ResourceType constant
 * @return				Value or -1 on failure.
 * @error				Invalid client index, client not in game or failed to find resource entity.
 * @deprecated          Use GetPlayerResourceEntity and GetEntProp instead.
 */
#pragma deprecated Use GetPlayerResourceEntity and GetEntProp instead
stock int TF2_GetPlayerResourceData(int client, TFResourceType type)
{
	if (!IsClientConnected(client))
	{
		return -1;
	}

	int offset = FindSendPropInfo("CTFPlayerResource", TFResourceNames[type]);

	if (offset < 1)
	{
		return -1;
	}

	int entity = TF2_GetResourceEntity();

	if (entity == -1)
	{
		return -1;
	}

	return GetEntData(entity, offset + (client*4));
}

/**
 * Sets client data in the resource entity
 *
 * Note: The game overwrites these values every frame, so changing them will have very little effect.
 *
 * @param client        Player's index.
 * @param type          ResourceType constant
 * @param value         Value to set.
 * @return              Value or -1 on failure.
 * @error               Invalid client index, client not in game or failed to find resource entity.
 * @deprecated          Use GetPlayerResourceEntity and SetEntProp instead.
 */
#pragma deprecated Use GetPlayerResourceEntity and SetEntProp instead
stock bool TF2_SetPlayerResourceData(int client, TFResourceType type, any value)
{
	if (!IsClientConnected(client))
	{
		return false;
	}

	int offset = FindSendPropInfo("CTFPlayerResource", TFResourceNames[type]);

	if (offset < 1)
	{
		return false;
	}

	int entity = TF2_GetResourceEntity();

	if (entity == -1)
	{
		return false;
	}

	SetEntData(entity, offset + (client*4), value);

	return true;
}

/**
 * Removes all weapons from a client's weapon slot
 *
 * @param client        Player's index.
 * @param slot          Slot index (0-5)
 * @error               Invalid client, invalid slot or lack of mod support
 */
stock void TF2_RemoveWeaponSlot(int client, int slot)
{
	int weaponIndex;
	while ((weaponIndex = GetPlayerWeaponSlot(client, slot)) != -1)
	{
		// bug #6206
		// papering over a valve bug where a weapon's extra wearables aren't properly removed from the weapon's owner
		int extraWearable = GetEntPropEnt(weaponIndex, Prop_Send, "m_hExtraWearable");
		if (extraWearable != -1)
		{
			TF2_RemoveWearable(client, extraWearable);
		}

		extraWearable = GetEntPropEnt(weaponIndex, Prop_Send, "m_hExtraWearableViewModel");
		if (extraWearable != -1)
		{
			TF2_RemoveWearable(client, extraWearable);
		}

		RemovePlayerItem(client, weaponIndex);
		AcceptEntityInput(weaponIndex, "Kill");
	}
}

/**
 * Removes all weapons from a client
 *
 * @param client        Player's index.
 */
stock void TF2_RemoveAllWeapons(int client)
{
	for (int i = 0; i <= 5; i++)
	{
		TF2_RemoveWeaponSlot(client, i);
	}
}

/**
 * Gets a player's condition bits
 *
 * @param client        Player's index.
 * @return              Player's condition bits
 * @deprecated          Use TF2_IsPlayerInCondition instead.
 */
#pragma deprecated Use TF2_IsPlayerInCondition instead.
stock int TF2_GetPlayerConditionFlags(int client)
{
	return GetEntProp(client, Prop_Send, "m_nPlayerCond")|GetEntProp(client, Prop_Send, "_condition_bits");
}

/**
 * Check whether or not a condition is set on a player
 *
 * @param client        Player's index.
 * @param cond          TFCond constant
 * @return              True if set, false otherwise
 */
stock bool TF2_IsPlayerInCondition(int client, TFCond cond)
{
	// Conditions are stored across multiple netprops now, one for each 32-bit segment.
	int iCond = view_as<int>(cond);
	switch (iCond / 32)
	{
		case 0:
		{
			int bit = 1 << iCond;
			if ((GetEntProp(client, Prop_Send, "m_nPlayerCond") & bit) == bit)
			{
				return true;
			}

			if ((GetEntProp(client, Prop_Send, "_condition_bits") & bit) == bit)
			{
				return true;
			}
		}
		case 1:
		{
			int bit = (1 << (iCond - 32));
			if ((GetEntProp(client, Prop_Send, "m_nPlayerCondEx") & bit) == bit)
			{
				return true;
			}
		}
		case 2:
		{
			int bit = (1 << (iCond - 64));
			if ((GetEntProp(client, Prop_Send, "m_nPlayerCondEx2") & bit) == bit)
			{
				return true;
			}
		}
		case 3:
		{
			int bit = (1 << (iCond - 96));
			if ((GetEntProp(client, Prop_Send, "m_nPlayerCondEx3") & bit) == bit)
			{
				return true;
			}
		}
		case 4:
		{
			int bit = (1 << (iCond - 128));
			if ((GetEntProp(client, Prop_Send, "m_nPlayerCondEx4") & bit) == bit)
			{
				return true;
			}
		}
		default:
		{
			ThrowError("Invalid TFCond value %d", iCond);
		}
	}

	return false;
}

/**
 * Gets an entity's object type.
 *
 * @param entity        Entity index.
 * @return              Current TFObjectType of entity.
 * @error               Invalid entity index.
 */
stock TFObjectType TF2_GetObjectType(int entity)
{
	int offset = GetEntSendPropOffs(entity, "m_iObjectType");

	if (offset <= 0)
	{
		ThrowError("Entity index %d is not an object", entity);
	}

	return view_as<TFObjectType>(GetEntData(entity, offset));
}

/**
 * Gets an entity's object mode.
 *
 * @param entity        Entity index.
 * @return              Current TFObjectMode of entity.
 * @error               Invalid entity index.
 */
stock TFObjectMode TF2_GetObjectMode(int entity)
{
	int offset = GetEntSendPropOffs(entity, "m_iObjectMode");

	if (offset <= 0)
	{
		ThrowError("Entity index %d is not an object", entity);
	}

	return view_as<TFObjectMode>(GetEntData(entity, offset));
}
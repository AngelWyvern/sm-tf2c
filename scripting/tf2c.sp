#include <sourcemod>
#include <sdktools>

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

// Game Config
Handle hGameConf;

// Offsets
Handle hForceRespawn;

// Signatures
Handle hBurn;
Handle hRemoveDisguise;
Handle hDisguise;
Handle hRegenerate;
Handle hAddCondition;
Handle hRemoveCondition;
 
public void OnPluginStart()
{
	hGameConf = LoadGameConfigFile("tf2classic.games");
	
	// Burn
	StartPrepSDKCall(SDKCall_Player);
	PrepSDKCall_SetFromConf(hGameConf, SDKConf_Virtual, "Burn");
	PrepSDKCall_AddParameter(SDKType_CBasePlayer, SDKPass_Pointer);
	hBurn = EndPrepSDKCall();
	
	// ForceRespawn
	StartPrepSDKCall(SDKCall_Player);
	PrepSDKCall_SetFromConf(hGameConf, SDKConf_Virtual, "ForceRespawn");
	hForceRespawn = EndPrepSDKCall();
	
	// Regenerate
	StartPrepSDKCall(SDKCall_Player);
	PrepSDKCall_SetFromConf(hGameConf, SDKConf_Signature, "Regenerate");
	hRegenerate = EndPrepSDKCall();
	
	// AddCondition
	StartPrepSDKCall(SDKCall_Player);
	PrepSDKCall_SetFromConf(hGameConf, SDKConf_Signature, "AddCondition");
	PrepSDKCall_AddParameter(SDKType_PlainOldData, SDKPass_Plain);
	PrepSDKCall_AddParameter(SDKType_Float, SDKPass_Plain);
	PrepSDKCall_AddParameter(SDKType_CBasePlayer, SDKPass_Pointer, VDECODE_FLAG_ALLOWNULL);
	hAddCondition = EndPrepSDKCall();
	
	// RemoveCondition
	StartPrepSDKCall(SDKCall_Player);
	PrepSDKCall_SetFromConf(hGameConf, SDKConf_Signature, "RemoveCondition");
	PrepSDKCall_AddParameter(SDKType_PlainOldData, SDKPass_Plain);
	hRemoveCondition = EndPrepSDKCall();
	
	// Disguise
	StartPrepSDKCall(SDKCall_Player);
	PrepSDKCall_SetFromConf(hGameConf, SDKConf_Signature, "Disguise");
	PrepSDKCall_AddParameter(SDKType_PlainOldData, SDKPass_Plain);
	PrepSDKCall_AddParameter(SDKType_PlainOldData, SDKPass_Plain);
	PrepSDKCall_AddParameter(SDKType_CBaseEntity, SDKPass_Pointer, VDECODE_FLAG_ALLOWNULL);
	hDisguise = EndPrepSDKCall();
	
	// RemoveDisguise
	StartPrepSDKCall(SDKCall_Player);
	PrepSDKCall_SetFromConf(hGameConf, SDKConf_Signature, "RemoveDisguise");
	hRemoveDisguise = EndPrepSDKCall();
	
	delete hGameConf;
	
	AddMultiTargetFilter("@red", Filter_Red, "red team", false);
	AddMultiTargetFilter("@blue", Filter_Blu, "blue team", false);
	AddMultiTargetFilter("@green", Filter_Grn, "green team", false);
	AddMultiTargetFilter("@yellow", Filter_Ylw, "yellow team", false);
}

public APLRes AskPluginLoad2(Handle myself, bool late, char[] error, int err_max)
{
	CreateNative("TF2_IgnitePlayer", Native_IgnitePlayer);
	CreateNative("TF2_RespawnPlayer", Native_RespawnPlayer);
	CreateNative("TF2_RegeneratePlayer", Native_RegeneratePlayer);
	CreateNative("TF2_AddCondition", Native_AddCondition);
	CreateNative("TF2_RemoveCondition", Native_RemoveCondition);
	CreateNative("TF2_DisguisePlayer", Native_DisguisePlayer);
	CreateNative("TF2_RemovePlayerDisguise", Native_RemovePlayerDisguise);
	return APLRes_Success;
}
 
public int Native_IgnitePlayer(Handle plugin, int numParams)
{
	int client = GetNativeCell(1);
	int attacker = GetNativeCell(2);
	SDKCall(hBurn, client, attacker);
}
 
public int Native_RespawnPlayer(Handle plugin, int numParams)
{
	int client = GetNativeCell(1);
	SDKCall(hForceRespawn, client);
}

public int Native_RegeneratePlayer(Handle plugin, int numParams)
{
	int client = GetNativeCell(1);
	SDKCall(hRegenerate, client);
}
 
public int Native_AddCondition(Handle plugin, int numParams)
{
	int client = GetNativeCell(1);
	int condition = GetNativeCell(2);
	float duration = GetNativeCell(3);
	int inflictor = GetNativeCell(4);
	SDKCall(hAddCondition, client, condition, duration, inflictor);
}
 
public int Native_RemoveCondition(Handle plugin, int numParams)
{
	int client = GetNativeCell(1);
	int condition = GetNativeCell(2);
	SDKCall(hRemoveCondition, client, condition);
}
 
public int Native_DisguisePlayer(Handle plugin, int numParams)
{
	int client = GetNativeCell(1);
	int team = GetNativeCell(2);
	int classType = GetNativeCell(3);
	int target = GetNativeCell(4);
	SDKCall(hDisguise, client, team, classType, target);
}
 
public int Native_RemovePlayerDisguise(Handle plugin, int numParams)
{
	int client = GetNativeCell(1);
	SDKCall(hRemoveDisguise, client);
}

public bool Filter_Red(const char[] pattern, Handle clients)
{
	for (int i = 1; i <= MaxClients; i++)
	{
		if (!IsValidClient(i))
			continue;
		
		if (Stock_GetClientTeam(i) == TFTeam_Red)
			PushArrayCell(clients, i);
	}
	return true;
}

public bool Filter_Blu(const char[] pattern, Handle clients)
{
	for (int i = 1; i <= MaxClients; i++)
	{
		if (!IsValidClient(i))
			continue;
		
		if (Stock_GetClientTeam(i) == TFTeam_Blue)
			PushArrayCell(clients, i);
	}
	return true;
}

public bool Filter_Grn(const char[] pattern, Handle clients)
{
	for (int i = 1; i <= MaxClients; i++)
	{
		if (!IsValidClient(i))
			continue;
		
		if (Stock_GetClientTeam(i) == TFTeam_Green)
			PushArrayCell(clients, i);
	}
	return true;
}

public bool Filter_Ylw(const char[] pattern, Handle clients)
{
	for (int i = 1; i <= MaxClients; i++)
	{
		if (!IsValidClient(i))
			continue;
		
		if (Stock_GetClientTeam(i) == TFTeam_Yellow)
			PushArrayCell(clients, i);
	}
	return true;
}

stock TFClassType Stock_GetPlayerClass(int client)
{
	switch (GetEntProp(client, Prop_Send, "m_iClass"))
	{
		case 0: return TFClass_Unknown;
		case 1: return TFClass_Scout;
		case 2: return TFClass_Sniper;
		case 3: return TFClass_Soldier;
		case 4: return TFClass_DemoMan;
		case 5: return TFClass_Medic;
		case 6: return TFClass_Heavy;
		case 7: return TFClass_Pyro;
		case 8: return TFClass_Spy;
		case 9: return TFClass_Engineer;
		case 10: return TFClass_Civilian;
		default: return TFClass_Unknown;
	}
}

stock TFTeam Stock_GetClientTeam(int client)
{
	switch (GetClientTeam(client))
	{
		case 0: return TFTeam_Unassigned;
		case 1: return TFTeam_Spectator;
		case 2: return TFTeam_Red;
		case 3: return TFTeam_Blue;
		case 4: return TFTeam_Green;
		case 5: return TFTeam_Yellow;
		default: return TFTeam_Unassigned;
	}
}

stock bool IsValidClient(int client)
{
	return client > 0 && client <= MaxClients && IsClientConnected(client) && IsClientInGame(client) && !IsClientSourceTV(client);
}
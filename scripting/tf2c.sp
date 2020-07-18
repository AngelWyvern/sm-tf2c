#include <sourcemod>
#include <sdktools>
 
Handle hGameConf;
Handle hRespawn;
 
public void OnPluginStart()
{
	hGameConf = LoadGameConfigFile("tf2classic.games");
	
	// Force Respawn
	StartPrepSDKCall(SDKCall_Player);
	PrepSDKCall_SetFromConf(hGameConf, SDKConf_Virtual, "ForceRespawn");
	hRespawn = EndPrepSDKCall();
	
	delete hGameConf;
}

public APLRes AskPluginLoad2(Handle myself, bool late, char[] error, int err_max)
{
	CreateNative("TF2_RespawnPlayer", Native_RespawnPlayer);
	return APLRes_Success;
}
 
public int Native_RespawnPlayer(Handle plugin, int numParams)
{
	int client = GetNativeCell(1);
	SDKCall(hRespawn, client);
}

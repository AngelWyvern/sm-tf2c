# Sourcemod TF2C
Here is a repository that includes some of the modern solutions to Sourcemod issues in the Team Fortress 2 Classic mod.

# Warning
The Beta branch is still being actively developed and not all plugins may not be supported yet. If it exists, please switch over to the release branch for more stable compatibility.

# Installation
For easier use of Sourcemod on TF2Classic, download Sourcemod and Metamod from the official website, then replace the sourcemod files with the files in this repository. This should ensure proper functionality of Sourcemod.

# Usage
With this installed, it will fix problems such as SDKTools/SDKHooks refusing to work, fix up menus, etc.. You can also code and execute plugins for TF2 with the same enum and function names, and this is actually pretty easy to do. If you're coding a plugin for TF2Classic, read the below category on Including Functions. If you are instead looking to convert an existing TF2 plugin, then read the below category on Converting Existing TF2 Plugins.
## Including Functions
Okay this is actually pretty simple. Instead of doing the ordinary such as `#include <tf2>` and `#include <tf2stocks>`, all you have to do is write `#include <tf2c>` and all the functions/enumerations from both of the other files should be there, and the tf2c include file contains more items in the enumerations for TF2Classic, such as `TFTeam_Green` or `TFClass_Civilian`, etc..
## Converting Existing TF2 Plugins
In most cases, you shouldn't have to do anything and the plugin should work just fine on its own, even if it is including the old tf2 includes. If it isn't working, you could instead try deleting the occurences of `#include <tf2>` and `#include <tf2stocks>` and replacing them with `#include <tf2c>`.

# Compatibility
Part of the goal of sm-tf2c is to allow compatibility of TF2 plugins in TF2Classic. (You can read how to convert them above.) This section here will show you what you can do so far with the <tf2c> include:
<br />
<br />
## Enumerations
###### TFClassType
TFClass_Unknown<br />
TFClass_Scout<br />
TFClass_Sniper<br />
TFClass_Soldier<br />
TFClass_DemoMan<br />
TFClass_Medic<br />
TFClass_Heavy<br />
TFClass_Pyro<br />
TFClass_Spy<br />
TFClass_Engineer<br />
TFClass_Civilian
###### TFTeam
TFTeam_Unassigned<br />
TFTeam_Spectator<br />
TFTeam_Red<br />
TFTeam_Blue<br />
TFTeam_Green<br />
TFTeam_Yellow
###### TFCond
TFCond_Slowed //0: Revving Minigun Sniper Rifle. Gives zoomed/revved pose<br />
TFCond_Zoomed //1: Sniper Rifle zooming<br />
TFCond_Disguising //2: Disguise smoke<br />
TFCond_Disguised //3: Disguise<br />
TFCond_Cloaked //4: Cloak effect<br />
TFCond_Ubercharged //5: Invulnerability removed when being healed or by another Uber effect<br />
TFCond_TeleportedGlow //6: Teleport trail effect<br />
TFCond_Taunting //7: Used for taunting can remove to stop taunting<br />
TFCond_UberchargeFading //8: Invulnerability expiration effect<br />
TFCond_Unknown1 //9<br />
TFCond_CloakFlicker //9: Cloak flickering effect<br />
TFCond_Teleporting //10: Used for teleporting does nothing applying<br />
TFCond_Kritzkrieged //11: Crit boost removed when being healed or another Uber effect<br />
TFCond_Unknown2 //12<br />
TFCond_TmpDamageBonus //12: Temporary damage buff something along with attribute 19<br />
TFCond_Dazed //15: Slow effect can remove to remove stun effects<br />
TFCond_Healing //21: Used for healing does nothing applying<br />
TFCond_OnFire //22: Ignite sound and vocals can remove to remove afterburn<br />
TFCond_Overhealed //23: Used for overheal does nothing applying<br />
TFCond_Jarated //24: Jarate effect<br />
TFCond_Bleeding //25: Bleed effect<br />
TFCond_MarkedForDeath //30: Fan o' War marked-for-death effect<br />
TFCond_HalloweenCritCandy //33: Halloween pumpkin crit-boost<br />
TFCond_CritCanteen //34: Crit-boost and doubles Sentry Gun fire-rate<br />
TFCond_CritDemoCharge //35: Crit glow adds TFCond_Charging when charge meter is below 75%<br />
TFCond_CritOnFirstBlood //37: Arena first blood crit-boost<br />
TFCond_CritOnWin //38: End-of-round crit-boost (May not remove correctly?)<br />
TFCond_CritOnFlagCapture //39: Intelligence capture crit-boost<br />
TFCond_CritOnKill //40: Crit-boost from crit-on-kill weapons<br />
TFCond_RestrictToMelee //41: Prevents switching once melee is out<br />
TFCond_MarkedForDeathSilent //48: Marked-for-death without sound effect<br />
TFCond_DisguisedAsDispenser //49: Dispenser disguise when crouching max movement speed sentries ignore player<br />
TFCond_UberchargedHidden //51: Non-visual uber effect will appear when damage is taken<br />
TFCond_UberchargedCanteen //52: Invulnerability effect and Sentry Gun damage resistance<br />
TFCond_HalloweenBombHead //53: Bomb head effect (semi-functional does not explode bomb is invisible)<br />
TFCond_CritOnDamage //56: Miscellaneous crit-boost<br />
TFCond_UberchargedOnTakeDamage //57: Miscellaneous invulnerability<br />
TFCond_Stealthed //64: Cloaked until next attack (semi-functional doesn't uncloak)<br />
TFCond_BulletImmune //67: Full bullet immunity<br />
TFCond_BlastImmune //68: Full blast immunity<br />
TFCond_FireImmune //69: Full fire immunity<br />
TFCond_HalloweenGiant //74: Double size x10 max health increase ammo regeneration and forced thirdperson<br />
TFCond_HalloweenTiny //75: Half size and increased head size<br />
TFCond_HalloweenGhostMode //77: Supposed to ghost you but instead you're just forced in thirdperson<br />
TFCond_BlastJumping //81: Player is blast jumping<br />
TFCond_KnockedIntoAir //115: Used when a player is airblasted
###### TFObjectType
TFObject_CartDispenser<br />
TFObject_Dispenser<br />
TFObject_Teleporter<br />
TFObject_Sentry<br />
TFObject_Sapper
###### TFObjectMode
TFObjectMode_None<br />
TFObjectMode_Entrance<br />
TFObjectMode_Exit
## Functions
`void TF2_RespawnPlayer(int client)`

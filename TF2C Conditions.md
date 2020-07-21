# TF2Classic Conditions
The following are the conditions I have found to be currently working, although it needs further testing with more than just one player.<br />
Format:<br />
TFCond_(Name) - The name of the condition that is used to call them in Sourcepawn.<br />
//(Number): (Description) - The number tells you what condition number you would have to use in addcond or removecond. The description informs you of what it does.
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

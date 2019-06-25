// 01. Search :
ACMD(do_cmd);

// 01. Add after :
#ifdef ENABLE_CHANGE_CHANNEL
ACMD(do_change_channel);
#endif


// 02. Search:
	{ 					"logout",								do_cmd,								SCMD_LOGOUT,		POS_DEAD,						GM_PLAYER						},

// 02. Add afer :
#ifdef ENABLE_CHANGE_CHANNEL
	{ 					"change_channel",						do_change_channel,					0,					POS_DEAD,						GM_PLAYER						},
#endif	
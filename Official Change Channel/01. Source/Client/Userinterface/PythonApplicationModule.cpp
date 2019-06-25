// 01. Search:
#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	0);
#endif

// 01. Add after :
#ifdef ENABLE_MOVE_CHANNEL
	PyModule_AddIntConstant(poModule, "ENABLE_MOVE_CHANNEL",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_MOVE_CHANNEL",	0);
#endif
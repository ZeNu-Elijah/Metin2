//1. Search:
#ifdef ENABLE_NEW_EQUIPMENT_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_NEW_EQUIPMENT_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_NEW_EQUIPMENT_SYSTEM",	0);
#endif
//1. Add after:
#ifdef ENABLE_FOG_FIX
	PyModule_AddIntConstant(poModule, "ENABLE_FOG_FIX",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_FOG_FIX",	0);
#endif
// 1. Search:
#ifdef USE_OPENID
// 1. Add before:
#ifdef ENABLE_SHOW_CHEST_DROP
	PyModule_AddIntConstant(poModule, "ENABLE_SHOW_CHEST_DROP",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_SHOW_CHEST_DROP",	0);
#endif
///caut�:
	int horse_ride(lua_State* L)
	{
		LPCHARACTER ch = CQuestManager::instance().GetCurrentCharacterPtr();

///adaug�:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
		if (ch->IsRidingMount())
			return 0;
		if (ch->GetMapIndex() == 113 || CArenaManager::instance().IsArenaMap(ch->GetMapIndex()) == true)
			return 0;		
#endif

///caut�:
	int horse_summon(lua_State* L)
	{
		LPCHARACTER ch = CQuestManager::instance().GetCurrentCharacterPtr();

///adaug�:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
		if (ch->IsRidingMount())
			return 0;
		if (ch->GetMapIndex() == 113 || CArenaManager::instance().IsArenaMap(ch->GetMapIndex()) == true)
			return 0;		
#endif
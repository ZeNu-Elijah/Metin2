// 1. Search:
		void __TEST_SetSkillGroupFake(int iIndex);
// 1. Add after:
#ifdef ENABLE_SHOW_CHEST_DROP
		bool 	SendChestDropInfo(WORD wInventoryCell);
		bool 	RecvChestDropInfo();
#endif
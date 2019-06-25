// 1. Search:
	Set(HEADER_CG_STATE_CHECKER, sizeof(BYTE), "ServerStateCheck", false);
// 1. Add after:
#ifdef ENABLE_SHOW_CHEST_DROP
	Set(HEADER_CG_CHEST_DROP_INFO, sizeof(TPacketCGChestDropInfo), "ChestDropInfo", true);
#endif
// 1. Search:
			Set(HEADER_GC_DRAGON_SOUL_REFINE,		CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketGCDragonSoulRefine), STATIC_SIZE_PACKET));
// 1. Add after:
#ifdef ENABLE_SHOW_CHEST_DROP
			Set(HEADER_GC_CHEST_DROP_INFO, CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketGCChestDropInfo), DYNAMIC_SIZE_PACKET));
#endif
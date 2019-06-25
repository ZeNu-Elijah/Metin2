// 01. Search in (public:)

void			OpenMyShop(const char * c_pszSign, TShopItemTable * pTable, BYTE bItemCount);

// 01. Add after :
#ifdef ENABLE_CHANGE_CHANNEL
		void 			ChangeChannel(DWORD channelId);
#endif


// 02. Search:
		LPEVENT				m_pkFishingEvent;
// 02. Add after :
#ifdef ENABLE_CHANGE_CHANNEL
		LPEVENT				m_pkChangeChannelEvent;
#endif

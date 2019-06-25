// 01. Search :
	// MINING
	m_pkMiningEvent = NULL;
	// END_OF_MINING
	
// 01. Add after :
#ifdef ENABLE_CHANGE_CHANNEL
	m_pkChangeChannelEvent = NULL;
#endif

// 02. Search :
	event_cancel(&m_pkFishingEvent);
// 02. Add after :
#ifdef ENABLE_CHANGE_CHANNEL
	event_cancel(&m_pkChangeChannelEvent);
#endif

// 03. Search :
	event_cancel(&m_pkFishingEvent);
// 03. Add after :

int	CHARACTER::GetSkillPowerByLevel(int level, bool bMob) const
{
	.....
}

#ifdef ENABLE_CHANGE_CHANNEL
void CHARACTER::ChangeChannel(DWORD channelId){
	long lAddr;
	long lMapIndex;
	WORD wPort;
	long x = this->GetX();
	long y = this->GetY();

	if (!CMapLocation::instance().Get(x, y, lMapIndex, lAddr, wPort)){
		sys_err("cannot find map location index %d x %d y %d name %s", lMapIndex, x, y, GetName());
		return;
	}
	
	if(lMapIndex >= 10000){
		this->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You can't change channel in private map."));
		return;
	}

	Stop();
	Save();
		    
	if(GetSectree()){
	    GetSectree()->RemoveEntity(this);
	    ViewCleanup();
	    EncodeRemovePacket(this);
	}
	TPacketGCWarp p;

	p.bHeader	= HEADER_GC_WARP;
	p.lX	= x;
	p.lY	= y;
	p.lAddr	= lAddr;
	
	p.wPort	= (wPort - 100*(g_bChannel-1) + 100*(channelId-1));
	
	GetDesc()->Packet(&p, sizeof(TPacketGCWarp));
}
#endif



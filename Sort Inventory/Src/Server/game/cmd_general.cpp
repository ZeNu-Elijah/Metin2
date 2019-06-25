///adaugã la sf.:
ACMD (do_sort_items)
{
	if (ch->IsDead())
	{
        ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Nu poti stoca itemele din inventar daca esti mort."));
        return;
	}
    if (ch->GetExchange() || ch->GetShopOwner() || ch->GetMyShop() || ch->IsOpenSafebox() || ch->IsCubeOpen()
#ifdef __ATTR_TRANSFER_SYSTEM__
	|| ch->IsAttrTransferOpen()
#endif	
	)
	{
        ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Nu poti stoca itemele din inventar daca ai o fereastra deschisa."));
        return;
	}
	
	if ((ch->m_sortLastUsed + 10) > get_global_time())
	{
		ch->ChatPacket(CHAT_TYPE_INFO, "Asteapta %d de secunde pana cand poti utiliza din nou aceasta optiune.", (ch->m_sortLastUsed + 10) - get_global_time());
		return;
	}

	for (int i = 0; i < INVENTORY_MAX_NUM; ++i)
	{
		LPITEM item = ch->GetInventoryItem(i);
		
		if(!item)
			continue;
		
		if(item->isLocked())
			continue;
		
		if(item->GetCount() == ITEM_MAX_COUNT)
			continue;
		
		if (item->IsStackable() && !IS_SET(item->GetAntiFlag(), ITEM_ANTIFLAG_STACK))
		{
			for (int j = i; j < INVENTORY_MAX_NUM; ++j)
			{
				LPITEM item2 = ch->GetInventoryItem(j);
				
				if(!item2)
					continue;
				
				if(item2->isLocked())
					continue;
	
				if (item2->GetVnum() == item->GetVnum())
				{
					bool bStopSockets = false;
					
					for (int k = 0; k < ITEM_SOCKET_MAX_NUM; ++k)
					{
						if (item2->GetSocket(k) != item->GetSocket(k))
						{
							bStopSockets = true;
							break;
						}
					}
					
					if(bStopSockets)
						continue;
	
					BYTE bAddCount = MIN(ITEM_MAX_COUNT - item->GetCount(), item2->GetCount());
	
					item->SetCount(item->GetCount() + bAddCount);
					item2->SetCount(item2->GetCount() - bAddCount);
					ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Ai stocat itemele cu succes."));
					
					continue;
				}
			}
		}
	}
}
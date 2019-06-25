///caut�:
		if (UNIQUE_SPECIAL_RIDE == item->GetSubType() && IS_SET(item->GetFlag(), ITEM_FLAG_QUEST_USE))
		{
			quest::CQuestManager::instance().UseItem(GetPlayerID(), item, false);
		}

///modific�:
		if (COSTUME_MOUNT == item->GetSubType())
		{
			quest::CQuestManager::instance().UseItem(GetPlayerID(), item, false);
		}
		if (
			(ITEM_UNIQUE == item->GetType() && UNIQUE_SPECIAL_RIDE == item->GetSubType() && IS_SET(item->GetFlag(), ITEM_FLAG_QUEST_USE))
			|| (ITEM_UNIQUE == item->GetType() && UNIQUE_SPECIAL_MOUNT_RIDE == item->GetSubType() && IS_SET(item->GetFlag(), ITEM_FLAG_QUEST_USE))
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
			|| (ITEM_COSTUME == item->GetType() && COSTUME_MOUNT == item->GetSubType())
#endif
		)
		{
			quest::CQuestManager::instance().UseItem(GetPlayerID(), item, false);
		}

///caut�:
				static BYTE abSlot[] = { WEAR_COSTUME_BODY, WEAR_COSTUME_HAIR };

///modific�:
				static BYTE abSlot[] = { WEAR_COSTUME_BODY, WEAR_COSTUME_HAIR, WEAR_COSTUME_MOUNT };

///caut�:
	{
		LPITEM u = GetWear(WEAR_UNIQUE2);

		if (u && u->GetVnum() == dwItemVnum)
			return true;
	}

///adaug�:
	{
		LPITEM u = GetWear(WEAR_COSTUME_MOUNT);

		if (u && u->GetVnum() == dwItemVnum)
			return true;
	}

///caut�:
	{
		LPITEM u = GetWear(WEAR_UNIQUE2);

		if (u && u->GetSpecialGroup() == (int)dwGroupVnum)
			return true;
	}

///adaug�:
	{
		LPITEM u = GetWear(WEAR_COSTUME_MOUNT);

		if (u && u->GetSpecialGroup() == (int)dwGroupVnum)
			return true;
	}

///caut�:
bool CHARACTER::UnEquipSpecialRideUniqueItem()
{
	LPITEM Unique1 = GetWear(WEAR_UNIQUE1);
	LPITEM Unique2 = GetWear(WEAR_UNIQUE2);

///adaug�:
	LPITEM Unique3 = GetWear(WEAR_COSTUME_MOUNT);

///caut�:
	if (NULL != Unique2)
	{
		if (UNIQUE_GROUP_SPECIAL_RIDE == Unique2->GetSpecialGroup())
		{
			return UnequipItem(Unique2);
		}
	}

///adaug�:
	if (NULL != Unique3)
	{
		if (UNIQUE_GROUP_SPECIAL_RIDE == Unique3->GetSpecialGroup())
		{
			return UnequipItem(Unique3);
		}
	}

///caut�:
	if (item->GetWearFlag() & WEARABLE_UNIQUE)
	{
		if ((GetWear(WEAR_UNIQUE1) && GetWear(WEAR_UNIQUE1)->IsSameSpecialGroup(item)) ||
			(GetWear(WEAR_UNIQUE2) && GetWear(WEAR_UNIQUE2)->IsSameSpecialGroup(item)))
		{
			ChatPacket(CHAT_TYPE_INFO, LC_TEXT("?? ??? ??? ??? ? ?? ??? ??? ? ????."));
			return false;
		}

		if (marriage::CManager::instance().IsMarriageUniqueItem(item->GetVnum()) && 
			!marriage::CManager::instance().IsMarried(GetPlayerID()))
		{
			ChatPacket(CHAT_TYPE_INFO, LC_TEXT("???? ?? ???? ??? ??? ? ????."));
			return false;
		}

	}

///modific�:
	if (item->GetWearFlag() & WEARABLE_UNIQUE)
	{
		if ((GetWear(WEAR_UNIQUE1) && GetWear(WEAR_UNIQUE1)->IsSameSpecialGroup(item)) ||
			(GetWear(WEAR_UNIQUE2) && GetWear(WEAR_UNIQUE2)->IsSameSpecialGroup(item)) ||
			(GetWear(WEAR_COSTUME_MOUNT) && GetWear(WEAR_COSTUME_MOUNT)->IsSameSpecialGroup(item)))
		{
			ChatPacket(CHAT_TYPE_INFO, LC_TEXT("?? ??? ??? ??? ? ?? ??? ??? ? ????."));
			return false;
		}

		if (marriage::CManager::instance().IsMarriageUniqueItem(item->GetVnum()) &&
			!marriage::CManager::instance().IsMarried(GetPlayerID()))
		{
			ChatPacket(CHAT_TYPE_INFO, LC_TEXT("???? ?? ???? ??? ??? ? ????."));
			return false;
		}

	}




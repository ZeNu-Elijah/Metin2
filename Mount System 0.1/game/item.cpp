///cautã:
		else if (GetSubType() == COSTUME_HAIR)
			return WEAR_COSTUME_HAIR;

///adaugã:
		else if (GetSubType() == COSTUME_MOUNT)
			return WEAR_COSTUME_MOUNT;

///cautã:
	for (int i = 0; i < ITEM_APPLY_MAX_NUM; ++i)
	{
		#ifdef __SASH_SYSTEM__
		if ((m_pProto->aApplies[i].bType == APPLY_NONE) && (GetType() != ITEM_COSTUME) && (GetSubType() != COSTUME_SASH))
		#else
		if (m_pProto->aApplies[i].bType == APPLY_NONE)
		#endif
			continue;

///adaugã:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
		if(IsMountItem())
			continue;
#endif

///cautã:
	m_pOwner->ComputeBattlePoints();

///adaugã:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (IsMountItem())
		ch->MountSummon(this);
#endif

///cautã:
	if (this != m_pOwner->GetWear(GetCell() - INVENTORY_MAX_NUM))
	{
		sys_err("m_pOwner->GetWear() != this");
		return false;
	}

///adaugã:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (IsMountItem())
		m_pOwner->MountUnsummon(this);
#endif

///cautã:
bool CItem::IsRideItem()
{
	if (ITEM_UNIQUE == GetType() && UNIQUE_SPECIAL_RIDE == GetSubType())
		return true;
	if (ITEM_UNIQUE == GetType() && UNIQUE_SPECIAL_MOUNT_RIDE == GetSubType())
		return true;

///adaugã:
	if (ITEM_COSTUME == GetType() && COSTUME_MOUNT == GetSubType())
		return true;

///adaugã la sf:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
bool CItem::IsMountItem()
{
	if (GetType() == ITEM_COSTUME && GetSubType() == COSTUME_MOUNT)
		return true;
	
	return false;
}
#endif
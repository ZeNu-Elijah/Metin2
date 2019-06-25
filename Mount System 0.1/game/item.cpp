///caut�:
		else if (GetSubType() == COSTUME_HAIR)
			return WEAR_COSTUME_HAIR;

///adaug�:
		else if (GetSubType() == COSTUME_MOUNT)
			return WEAR_COSTUME_MOUNT;

///caut�:
	for (int i = 0; i < ITEM_APPLY_MAX_NUM; ++i)
	{
		#ifdef __SASH_SYSTEM__
		if ((m_pProto->aApplies[i].bType == APPLY_NONE) && (GetType() != ITEM_COSTUME) && (GetSubType() != COSTUME_SASH))
		#else
		if (m_pProto->aApplies[i].bType == APPLY_NONE)
		#endif
			continue;

///adaug�:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
		if(IsMountItem())
			continue;
#endif

///caut�:
	m_pOwner->ComputeBattlePoints();

///adaug�:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (IsMountItem())
		ch->MountSummon(this);
#endif

///caut�:
	if (this != m_pOwner->GetWear(GetCell() - INVENTORY_MAX_NUM))
	{
		sys_err("m_pOwner->GetWear() != this");
		return false;
	}

///adaug�:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (IsMountItem())
		m_pOwner->MountUnsummon(this);
#endif

///caut�:
bool CItem::IsRideItem()
{
	if (ITEM_UNIQUE == GetType() && UNIQUE_SPECIAL_RIDE == GetSubType())
		return true;
	if (ITEM_UNIQUE == GetType() && UNIQUE_SPECIAL_MOUNT_RIDE == GetSubType())
		return true;

///adaug�:
	if (ITEM_COSTUME == GetType() && COSTUME_MOUNT == GetSubType())
		return true;

///adaug� la sf:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
bool CItem::IsMountItem()
{
	if (GetType() == ITEM_COSTUME && GetSubType() == COSTUME_MOUNT)
		return true;
	
	return false;
}
#endif
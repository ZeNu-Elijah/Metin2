///caut�:
		if (pkChr->IsNPC() && !pkChr->IsPet() && pkChr->GetRider() == NULL)

///modific�:
		if (pkChr->IsNPC() && !pkChr->IsPet() && !pkChr->IsMount() && pkChr->GetRider() == NULL)

///caut�:
ACMD(do_horse_summon)
{

///adaug�:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (ch->IsRidingMount())
		return;
#endif

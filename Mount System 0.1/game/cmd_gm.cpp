///cautã:
		if (pkChr->IsNPC() && !pkChr->IsPet() && pkChr->GetRider() == NULL)

///modificã:
		if (pkChr->IsNPC() && !pkChr->IsPet() && !pkChr->IsMount() && pkChr->GetRider() == NULL)

///cautã:
ACMD(do_horse_summon)
{

///adaugã:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (ch->IsRidingMount())
		return;
#endif

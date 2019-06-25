//01 : Search :

void CHARACTER::AttackedByPoison(LPCHARACTER pkAttacker)
{
	if (m_pkPoisonEvent)
		return;

	
// 01 : Add after :

#ifdef ENABLE_DUEL_OPTIONS
	if(CPVPManager::instance().IsSpecialDuel(pkAttacker, this))
		return;
#endif

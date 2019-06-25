// 01 : Search (x2):

if (number(1, 100) <= iCriticalPct)
	
// 01 : Replace with :

#ifdef ENABLE_DUEL_OPTIONS
				if (number(1, 100) <= iCriticalPct && !CPVPManager::instance().IsSpecialDuel(pAttacker, this))
#else
				if (number(1, 100) <= iCriticalPct)
#endif

//01 : Search :

	m_bRevenge = false;
	
//01 : Add after :

#ifdef ENABLE_DUEL_OPTIONS
	m_bIsSpecialDuel = false;
#endif


//02 : Search :

m_bRevenge = k.m_bRevenge;

//02 :  Add after :

#ifdef ENABLE_DUEL_OPTIONS
	m_bIsSpecialDuel = k.m_bIsSpecialDuel;
#endif


//03 : Search :

void CPVPManager::Insert(LPCHARACTER pkChr, LPCHARACTER pkVictim)

//03 :  Add after :

#ifdef ENABLE_DUEL_OPTIONS
void CPVPManager::Insert(LPCHARACTER pkChr, LPCHARACTER pkVictim, bool bSpecialDuelStatus)
#endif


//04. Search IN if (pkPVP->Agree(pkChr->GetPlayerID())) !!! :

				pkVictim->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("The duel with %s has begun!"), pkChr->GetName()); // la voi sunt in koreana pizdi.
				pkChr->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("The duel with %s has begun!"), pkVictim->GetName());	
				
//04. Replace with :

#ifdef ENABLE_DUEL_OPTIONS
			if(pkPVP->IsRevenge())
			{
				pkPVP->SetSpecialDuelStatus(bSpecialDuelStatus);
			}
			else
			{
				bSpecialDuelStatus = pkPVP->IsSpecialDuel();
			}
			
			if(bSpecialDuelStatus == true)
			{
				pkVictim->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Duelul cu %s a inceput ! (fara critica patrundere otrava)"), pkChr->GetName());
				pkChr->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Duelul cu %s a inceput ! (fara critica patrundere otrava)"), pkVictim->GetName());
			}
			else
			{
				pkVictim->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("The duel with %s has begun!"), pkChr->GetName());
				pkChr->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("The duel with %s has begun!"), pkVictim->GetName());
			}
#else
				pkVictim->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("The duel with %s has begun!"), pkChr->GetName());
				pkChr->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("The duel with %s has begun!"), pkVictim->GetName());
#endif


//05 Search :

m_map_pkPVPSetByID[pkVictim->GetPlayerID()].insert(pkPVP);

//05 Add after : 

#ifdef ENABLE_DUEL_OPTIONS
	pkPVP->SetSpecialDuelStatus(bSpecialDuelStatus);
#endif

//06 AFTER - char msg[CHAT_MAX_LEN + 1]; Search :

snprintf(msg, sizeof(msg), LC_TEXT("%s challenged you for a duel!"), pkChr->GetName());

//06 Replace with :


#ifdef ENABLE_DUEL_OPTIONS
	if(bSpecialDuelStatus == true)
		snprintf(msg, sizeof(msg), LC_TEXT("%s te-a provocat la duel fara critica, patrundere si otrava."), pkChr->GetName());
	else
		snprintf(msg, sizeof(msg), LC_TEXT("%s challenged you for a duel!"), pkChr->GetName());
#else
	snprintf(msg, sizeof(msg), LC_TEXT("%s challenged you for a duel!"), pkChr->GetName());
#endif


///////////////////////////////////////////////////////////////


// After :

void CPVPManager::Insert(LPCHARACTER pkChr, LPCHARACTER pkVictim)
{
	
						.....
						
}


// Add :

#ifdef ENABLE_DUEL_OPTIONS
bool CPVPManager::IsSpecialDuel(LPCHARACTER pkChr, LPCHARACTER pkVictim)
{
	if(!pkChr || !pkVictim)
		return false;
	
	if (pkChr == pkVictim)
		return false;
	
	if (!pkChr->IsPC() || !pkVictim->IsPC())
		return false;
	
	CPVPSetMap::iterator it = m_map_pkPVPSetByID.find(pkChr->GetPlayerID());

	if (it == m_map_pkPVPSetByID.end())
		return false;

	bool isSpecialDuel = false;

	TR1_NS::unordered_set<CPVP*>::iterator itSecond = it->second.begin();

	while (itSecond != it->second.end())
	{
		CPVP * pkPVP = *itSecond++;

		DWORD dwCompanionPID = pkPVP->m_players[0].dwPID == pkChr->GetPlayerID() ? pkPVP->m_players[1].dwPID : pkPVP->m_players[0].dwPID;

		if (dwCompanionPID == pkVictim->GetPlayerID())
		{
			if (pkPVP->IsFight() && pkPVP->IsSpecialDuel())
			{
				isSpecialDuel = true;
				break;
			}
		}
	}

	return isSpecialDuel;
}
#endif

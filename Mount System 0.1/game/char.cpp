///adaugã:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
#include "MountSystem.h"
#endif


///cautã:
	m_pointsInstant.iDragonSoulActiveDeck = -1;

///adaugã:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	m_mountSystem = 0;
	m_bIsMount = false;
#endif


///cautã:
	if (m_pkDungeon)
	{
		SetDungeon(NULL);
	}

///adaugã:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (m_mountSystem)
	{
		m_mountSystem->Destroy();
		delete m_mountSystem;

		m_mountSystem = 0;
	}
	
	if(GetMountVnum())
	{
		RemoveAffect(AFFECT_MOUNT);
		RemoveAffect(AFFECT_MOUNT_BONUS);
	}
	HorseSummon(false);
#endif


///cautã:
	MessengerManager::instance().Logout(GetName());

///adaugã:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if(GetMountVnum())
	{
		RemoveAffect(AFFECT_MOUNT);
		RemoveAffect(AFFECT_MOUNT_BONUS);
	}
#endif


///cautã:
#ifdef __PET_SYSTEM__
	// NOTE: ?? ???? PC? ???? PetSystem? ??? ?. ?? ??? ??? ?????? NPC?? ?? ?..
	if (m_petSystem)
	{
		m_petSystem->Destroy();
		delete m_petSystem;
	}

	m_petSystem = M2_NEW CPetSystem(this);
#endif

///adaugã:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (m_mountSystem)
	{
		m_mountSystem->Destroy();
		delete m_mountSystem;
	}

	m_mountSystem = M2_NEW CMountSystem(this);
#endif


///cautã:
	if (IsPC())
	{
		// ? ?? ?? ?? ?? ??? ?? ?? ???? ??? ?? ???.
		// ??? ?? ?? ??? ?? ?????, ??/??? ?? ?? ??
		// ????? ? ???? ? ???.
		if (GetMountVnum()) 
		{
			if (GetHorseST() > GetPoint(POINT_ST))
				PointChange(POINT_ST, GetHorseST() - GetPoint(POINT_ST));

			if (GetHorseDX() > GetPoint(POINT_DX))
				PointChange(POINT_DX, GetHorseDX() - GetPoint(POINT_DX));

			if (GetHorseHT() > GetPoint(POINT_HT))
				PointChange(POINT_HT, GetHorseHT() - GetPoint(POINT_HT));

			if (GetHorseIQ() > GetPoint(POINT_IQ))
				PointChange(POINT_IQ, GetHorseIQ() - GetPoint(POINT_IQ));
		}

	}

///modificã:
	if (IsPC())
	{
		if (GetMountVnum() && !GetWear(WEAR_COSTUME_MOUNT))
		{
			if (GetHorseST() > GetPoint(POINT_ST))
				PointChange(POINT_ST, GetHorseST() - GetPoint(POINT_ST));

			if (GetHorseDX() > GetPoint(POINT_DX))
				PointChange(POINT_DX, GetHorseDX() - GetPoint(POINT_DX));

			if (GetHorseHT() > GetPoint(POINT_HT))
				PointChange(POINT_HT, GetHorseHT() - GetPoint(POINT_HT));

			if (GetHorseIQ() > GetPoint(POINT_IQ))
				PointChange(POINT_IQ, GetHorseIQ() - GetPoint(POINT_IQ));
		}

	}


///cautã:
BYTE CHARACTER::GetChatCounter() const
{
	return m_bChatCounter;
}

///adaugã:
BYTE CHARACTER::GetMountCounter() const
{
	return m_bMountCounter;
}

void CHARACTER::ResetMountCounter()
{
	m_bMountCounter = 0;
}

BYTE CHARACTER::IncreaseMountCounter()
{
	return ++m_bMountCounter;
}

///adaugã la sf:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
void CHARACTER::MountSummon(LPITEM mountItem)
{
#define MOUNT_SYSTEM_FIX_POLY
#ifdef MOUNT_SYSTEM_FIX_POLY
	if (IsPolymorphed() == true)
	{
		ChatPacket(CHAT_TYPE_INFO, "Nu poti folosi un mount atat timp cat esti transformat.");
		return; 
	}
#endif	
	if (GetMapIndex() == 113)
		return;
	
	if (CArenaManager::instance().IsArenaMap(GetMapIndex()) == true)
		return;

	CMountSystem* mountSystem = GetMountSystem();
	DWORD mobVnum = 0;
	
	if (!mountSystem || !mountItem)
		return;
				
#ifdef __CHANGELOOK_SYSTEM__	
	if(mountItem->GetTransmutation())
	{
		const TItemTable* itemTable = ITEM_MANAGER::instance().GetTable(mountItem->GetTransmutation());
		
		if (itemTable)
			mobVnum = itemTable->alValues[1];
		else
			mobVnum = mountItem->GetValue(1);
	}
	else
		mobVnum = mountItem->GetValue(1);
#else
	if(mountItem->GetValue(1) != 0)
		mobVnum = mountItem->GetValue(1);
#endif
	
	if (IsHorseRiding())
		StopRiding();
	
	if (GetHorse())
		HorseSummon(false);
	
	mountSystem->Summon(mobVnum, mountItem, false);
}

void CHARACTER::MountUnsummon(LPITEM mountItem)
{
	CMountSystem* mountSystem = GetMountSystem();
	DWORD mobVnum = 0;
	
	if (!mountSystem || !mountItem)
		return;
	
#ifdef __CHANGELOOK_SYSTEM__	
	if(mountItem->GetTransmutation())
	{
		const TItemTable* itemTable = ITEM_MANAGER::instance().GetTable(mountItem->GetTransmutation());
		
		if (itemTable)
			mobVnum = itemTable->alValues[1];
		else
			mobVnum = mountItem->GetValue(1);
	}
	else
		mobVnum = mountItem->GetValue(1);
#else
	if(mountItem->GetValue(1) != 0)
		mobVnum = mountItem->GetValue(1);
#endif
	
	if (GetMountVnum() == mobVnum)
		mountSystem->Unmount(mobVnum);

	mountSystem->Unsummon(mobVnum);
}

void CHARACTER::CheckMount()
{
	CMountSystem* mountSystem = GetMountSystem();
	LPITEM mountItem = GetWear(WEAR_COSTUME_MOUNT);
	DWORD mobVnum = 0;
	
	if (!mountSystem || !mountItem)
		return;
	
#ifdef __CHANGELOOK_SYSTEM__	
	if(mountItem->GetTransmutation())
	{
		const TItemTable* itemTable = ITEM_MANAGER::instance().GetTable(mountItem->GetTransmutation());
		
		if (itemTable)
			mobVnum = itemTable->alValues[1];
		else
			mobVnum = mountItem->GetValue(1);
	}
	else
		mobVnum = mountItem->GetValue(1);
#else
	if(mountItem->GetValue(1) != 0)
		mobVnum = mountItem->GetValue(1);
#endif
	
	if(mountSystem->CountSummoned() == 0)
	{
		mountSystem->Summon(mobVnum, mountItem, false);
	}
}

bool CHARACTER::IsRidingMount()
{
	return (GetWear(WEAR_COSTUME_MOUNT) || FindAffect(AFFECT_MOUNT));
}
#endif


///cautã:
	m_bChatCounter = 0;

///adaugã:
	m_bMountCounter = 0;











///adaug�:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
#include "MountSystem.h"
#endif

///caut�:
	if (g_noticeBattleZone)
	{
		if (FN_is_battle_zone(ch))
		{
			ch->ChatPacket(CHAT_TYPE_NOTICE, LC_TEXT("? ??? ???? ??? ??? ? ????."));
			ch->ChatPacket(CHAT_TYPE_NOTICE, LC_TEXT("? ??? ???? ???"));
			ch->ChatPacket(CHAT_TYPE_NOTICE, LC_TEXT("??? ?? ? ???? ????? ????."));
		}
	}

///adaug�:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (ch->GetMapIndex() != 113 && CArenaManager::instance().IsArenaMap(ch->GetMapIndex()) == false)
	{
		ch->CheckMount();
	}
#endif

///caut�:
	else if (ch->GetMapIndex() == 113)
	{
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
		if (ch->IsHorseRiding() == true)
		{
			ch->StopRiding();
			ch->HorseSummon(false);
		}

		ch->RemoveAffect(AFFECT_MOUNT);
		ch->RemoveAffect(AFFECT_MOUNT_BONUS);
		if (ch->IsRiding())
			ch->StopRiding();
#endif
///adaug�:


///caut�:


///adaug�:


///caut�:


///adaug�:
///cautã:
void CHARACTER::__StateIdle_NPC()
{
	MonsterChat(MONSTER_CHAT_WAIT);
	m_dwStateDuration = PASSES_PER_SEC(5);

///adaugã:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (IsMount())
		return;
#endif


// 01. Search :
bool timed_event_cancel(LPCHARACTER ch)
{
	if (ch->m_pkTimedEvent)
	{
		event_cancel(&ch->m_pkTimedEvent);
		return true;
	}
	
// 01. Add after :

#ifdef ENABLE_CHANGE_CHANNEL
	if (ch->m_pkChangeChannelEvent)
	{
		event_cancel(&ch->m_pkChangeChannelEvent);
		return true;
	}
#endif



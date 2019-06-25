// 01. Search :
EVENTINFO(TimedEventInfo)
{
	DynamicCharacterPtr ch;
	int		subcmd;
	int         	left_second;
	char		szReason[MAX_REASON_LEN];

	TimedEventInfo()
	: ch()
	, subcmd( 0 )
	, left_second( 0 )
	{
		::memset( szReason, 0, MAX_REASON_LEN );
	}
};

// 01. Add after :
#ifdef ENABLE_CHANGE_CHANNEL
EVENTINFO(ChangeChannelEventInfo)
{
	DynamicCharacterPtr ch;
	int				channel_number;
	int         	left_second;

	ChangeChannelEventInfo()
	: ch()
	, channel_number( 0 )
	, left_second( 0 )
	{
	}
};
#endif

// 02. Search:
EVENTFUNC(timed_event)
{
		......
}

// 02. Add afer :
#ifdef ENABLE_CHANGE_CHANNEL
EVENTFUNC(change_channel_event)
{
	ChangeChannelEventInfo * info = dynamic_cast<ChangeChannelEventInfo *>( event->info );

	if ( info == NULL )
	{
		sys_err( "change_channel_event> <Factor> Null pointer" );
		return 0;
	}

	LPCHARACTER	ch = info->ch;
	if (ch == NULL) { // <Factor>
		return 0;
	}

	if (info->left_second <= 0)
	{
		ch->m_pkChangeChannelEvent = NULL;

		ch->ChangeChannel(info->channel_number);
	
		return 0;
	}
	else
	{
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Change channel in %d seconds."), info->left_second);
		--info->left_second;
	}

	return PASSES_PER_SEC(1);
}
#endif


// Add where you want :
#ifdef ENABLE_CHANGE_CHANNEL
ACMD(do_change_channel)
{
	char arg1[256];
	one_argument(argument, arg1, sizeof(arg1));

	DWORD channel_number = 0;
	str_to_number(channel_number, arg1);
	
	//if (ch->m_pkChangeChannelEvent)
	//{
	//	ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Change channel canceled."));
	//	event_cancel(&ch->m_pkChangeChannelEvent);
	//	return;
	//}
	
	if(!ch)
	{
		return;	
	}
	
	if(channel_number == 99 || g_bChannel == 99){
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You can't change channel in this map."));
		return;		
	}
	
	if(channel_number == g_bChannel)
	{
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You are already in this channel."));
		return;		
	}
	
    if (ch->IsDead() || !ch->CanWarp())
	{
        ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You can't do that now. Wait 10 seconds and try again."));
        return;
	}
	
	if(channel_number <= 0 || channel_number > 6)
	{
        ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("This channel is not valid."));
        return;
	}
	
	if (channel_number != 0)
	{
		if (ch->m_pkChangeChannelEvent)
		{
			ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Change channel canceled."));
			event_cancel(&ch->m_pkChangeChannelEvent);
			return;
		}
	
		ChangeChannelEventInfo* info = AllocEventInfo<ChangeChannelEventInfo>();
	
		{
			if (ch->IsPosition(POS_FIGHTING))
				info->left_second = 10;
			else
				info->left_second = 3;
		}
	
		info->ch					= ch;
		info->channel_number		= channel_number;
	
		ch->m_pkChangeChannelEvent	= event_create(change_channel_event, info, 1);
	}
}
#endif

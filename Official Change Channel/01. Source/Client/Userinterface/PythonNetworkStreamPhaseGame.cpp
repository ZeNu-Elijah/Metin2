// Search :
bool CPythonNetworkStream::RecvChannelPacket()
{
	..............
}
	
// Replace with this:	
	
bool CPythonNetworkStream::RecvChannelPacket(){
	TPacketGCChannel kChannelPacket;
	if (!Recv(sizeof(kChannelPacket), &kChannelPacket))
		return false;
#ifdef ENABLE_MOVE_CHANNEL
	PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "RefreshChannel", Py_BuildValue("(i)", kChannelPacket.channel));
#endif
	return true;
}

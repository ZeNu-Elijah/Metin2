// 1. Search:
			case HEADER_GC_HYBRIDCRYPT_SDB:
				RecvHybridCryptSDBPacket();
				return;
				break;
// 1. Add after:
#ifdef ENABLE_SHOW_CHEST_DROP
			case HEADER_GC_CHEST_DROP_INFO:
				ret = RecvChestDropInfo();
				break;
#endif



// 2. Go at the end of the file and add:
#ifdef ENABLE_SHOW_CHEST_DROP
bool CPythonNetworkStream::SendChestDropInfo(WORD wInventoryCell)
{
	TPacketCGChestDropInfo packet;
	packet.header = HEADER_CG_CHEST_DROP_INFO;
	packet.wInventoryCell = wInventoryCell;
	
	if (!Send(sizeof(packet), &packet))
		return false;

	return SendSequence();
}

bool CPythonNetworkStream::RecvChestDropInfo()
{
	TPacketGCChestDropInfo packet;
	if (!Recv(sizeof(packet), &packet))
		return false;

	packet.wSize -= sizeof(packet);
	while (packet.wSize > 0)
	{
		TChestDropInfoTable kTab;
		if (!Recv(sizeof(kTab), &kTab))
			return false;

		PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "BINARY_AddChestDropInfo", Py_BuildValue("(iiiii)", packet.dwChestVnum, kTab.bPageIndex, kTab.bSlotIndex, kTab.dwItemVnum, kTab.bItemCount));

		packet.wSize -= sizeof(kTab);
	}

	PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "BINARY_RefreshChestDropInfo", Py_BuildValue("(i)", packet.dwChestVnum));

	return true;
}
#endif


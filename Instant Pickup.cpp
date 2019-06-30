// 1. PythonPlayerInput.cpp
// 1.0. Search:
void CPythonPlayer::PickCloseItem()
{
	...
}
// 1.0. Add after:
void CPythonPlayer::PickCloseItemVector()
{
	CInstanceBase * pkInstMain = NEW_GetMainActorPtr();
	if (!pkInstMain)
		return;

	TPixelPosition kPPosMain;
	pkInstMain->NEW_GetPixelPosition(&kPPosMain);

	std::vector<DWORD> itemVidList;
	
	CPythonItem& rkItem=CPythonItem::Instance();
	if (!rkItem.GetCloseItemVector(pkInstMain->GetNameString(), kPPosMain, itemVidList))
		return;
	
	if(itemVidList.empty())
		return;
	
	for(int i = 0; i < itemVidList.size(); i++)
		SendClickItemPacket(itemVidList[i]);
}


// 2. PythonItem.cpp
// 2.0. Search:
bool CPythonItem::GetCloseItem (const std::string& myName, const TPixelPosition& c_rPixelPosition, DWORD* pdwItemID, DWORD dwDistance)
{
	....
}
// 2.0. Add after:
bool CPythonItem::GetCloseItemVector(const std::string& myName, const TPixelPosition& c_rPixelPosition, std::vector<DWORD>& itemVidList)
{
	DWORD dwCloseItemDistance = 1000 * 1000;
	
	TGroundItemInstanceMap::iterator i;
	for (i = m_GroundItemInstanceMap.begin(); i != m_GroundItemInstanceMap.end(); ++i)
	{
		TGroundItemInstance * pInstance = i->second;

		DWORD dwxDistance = DWORD(c_rPixelPosition.x - pInstance->v3EndPosition.x);
		DWORD dwyDistance = DWORD(c_rPixelPosition.y - (-pInstance->v3EndPosition.y));
		DWORD dwDistance = DWORD(dwxDistance * dwxDistance + dwyDistance * dwyDistance);

		if (dwDistance < dwCloseItemDistance && (pInstance->stOwnership == "" || pInstance->stOwnership == myName))
		{
			itemVidList.push_back(i->first);
		}
	}

	return true;
}


// 3. PythonItem.h
// 3.0. Search:
		bool	GetCloseMoney(const TPixelPosition & c_rPixelPosition, DWORD* dwItemID, DWORD dwDistance=300);
// 3.0. Adauga sub:
		bool 	GetCloseItemVector(const std::string& myName, const TPixelPosition& c_rPixelPosition, std::vector<DWORD>& itemVidList);
		
		
// 4. PythonPlayer.cpp
// 4.0. Search and replace:
void CPythonPlayer::SendClickItemPacket(DWORD dwIID)
{
	if (IsObserverMode())
		return;
		
	const char * c_szOwnerName;
	if (!CPythonItem::Instance().GetOwnership(dwIID, &c_szOwnerName))
		return;

	if (strlen(c_szOwnerName) > 0)
	if (0 != strcmp(c_szOwnerName, GetName()))
	{
		CItemData * pItemData;
		if (!CItemManager::Instance().GetItemDataPointer(CPythonItem::Instance().GetVirtualNumberOfGroundItem(dwIID), &pItemData))
		{
			Tracenf("CPythonPlayer::SendClickItemPacket(dwIID=%d) : Non-exist item.", dwIID);
			return;
		}
		
		if (!IsPartyMemberByName(c_szOwnerName) || pItemData->IsAntiFlag(CItemData::ITEM_ANTIFLAG_DROP | CItemData::ITEM_ANTIFLAG_GIVE))
		{
			PyCallClassMemberFunc(m_ppyGameWindow, "OnCannotPickItem", Py_BuildValue("()"));
			return;
		}
	}

	CPythonNetworkStream& rkNetStream=CPythonNetworkStream::Instance();
	rkNetStream.SendItemPickUpPacket(dwIID);
}


// 5. PythonPlayerModule.cpp
// 5.0. Search:
PyObject * playerPickCloseItem(PyObject* poSelf, PyObject* poArgs)
{
	CPythonPlayer::Instance().PickCloseItem();
	return Py_BuildNone();
}
// 5.0. Add after:
PyObject * playerPickCloseItemVector(PyObject* poSelf, PyObject* poArgs)
{
	CPythonPlayer::Instance().PickCloseItemVector();
	return Py_BuildNone();
}

// 5.1. Search:
		{ "PickCloseItem",				playerPickCloseItem,				METH_VARARGS },
// 5.1.Add after::
		{ "PickCloseItemVector",		playerPickCloseItemVector,			METH_VARARGS },
		
		
		
// 6. PythonPlayer,h
// 6.0. Search:
		void	PickCloseItem();
// 6.0. Add after:
		void 	PickCloseItemVector();
		
		
		
// 7. game.py 
// 7. Search:
	player.PickCloseItem()
// 7. Replace with:
	player.PickCloseItemVector()
	

// You can make option for fast pickup or not.
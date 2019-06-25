import uiCommon, snd, chat, app, net, player, item, wndMgr, mouseModule, localeInfo, constInfo, ui

class ChestDropWindow(ui.ScriptWindow):
	def __init__(self):
		ui.ScriptWindow.__init__(self)
		
		self.tooltipItem = None

		self.currentChest = 0
		self.currentPage = 1
		self.openAmount = 1
		self.invItemPos = -1
		
		self.chestDrop = { }

		self.__LoadWindow()

	def __del__(self):
		ui.ScriptWindow.__del__(self)
		
	def __LoadWindow(self):
		try:
			PythonScriptLoader = ui.PythonScriptLoader()
			PythonScriptLoader.LoadScriptFile(self, "UIScript/chestdropwindow.py")
		except:
			import exception
			exception.Abort("ChestDropWindow.__LoadWindow.LoadObject")

		try:
			self.titleBar = self.GetChild("TitleBar")

			self.openItemSlot = self.GetChild("OpenItemSlot")
			self.openCountController = self.GetChild("OpenCountController")
			self.openChestButtonSingle = self.GetChild("OpenChestButtonSingle")
			self.openChestButtonMultiple = self.GetChild("OpenChestButtonMultiple")
			
			self.prevButton = self.GetChild("prev_button")
			self.nextButton = self.GetChild("next_button")
			self.currentPageBack = self.GetChild("CurrentPageBack")
			self.currentPageText = self.GetChild("CurrentPage")
		except:
			import exception
			exception.Abort("ChestDropWindow.__LoadWindow.BindObject")
			
		self.titleBar.SetCloseEvent(ui.__mem_func__(self.Close))
		self.openCountController.SetEvent(ui.__mem_func__(self.OnChangeOpenAmount))
		
		self.openChestButtonSingle.SetEvent(ui.__mem_func__(self.OnClickOpenChest))
		self.openChestButtonMultiple.SetEvent(ui.__mem_func__(self.OnClickOpenChest))
		
		self.SetOpenAmount(1)
		
		self.prevButton.SetEvent(ui.__mem_func__(self.OnClickPrevPage))
		self.nextButton.SetEvent(ui.__mem_func__(self.OnClickNextPage))
		
		self.currentPageText.SetText(str(self.currentPage))

		wndItem = ui.GridSlotWindow()
		wndItem.SetParent(self)
		wndItem.SetPosition(8, 35)
		wndItem.SetSlotStyle(wndMgr.SLOT_STYLE_NONE)
		wndItem.SetOverInItemEvent(ui.__mem_func__(self.OverInItem))
		wndItem.SetOverOutItemEvent(ui.__mem_func__(self.OverOutItem))
		wndItem.ArrangeSlot(0, 15, 5, 32, 32, 0, 0)
		wndItem.RefreshSlot()
		wndItem.SetSlotBaseImage("d:/ymir work/ui/public/Slot_Base.sub", 1.0, 1.0, 1.0, 1.0)
		wndItem.Show()
		
		self.wndItem = wndItem
		
	def Close(self):
		self.invItemPos = -1
		self.Hide()
		
	def Destroy(self):
		self.ClearDictionary()
		
		self.tooltipItem = None
		self.wndItem = None
		
		self.currentChest = 0
		self.currentPage = 1
		self.openAmount = 1
		self.invItemPos = -1
		self.chestDrop = { }
		
	def SetOpenAmount(self, amount):
		self.openAmount = amount
		self.openChestButtonSingle.SetText("Deschide %d cufere" % self.openAmount)
		self.openChestButtonMultiple.SetText("Deschide %d cufere" % self.openAmount)
		
	def Open(self, invItemPos = -1):
		self.currentChest = 0
		self.currentPage = 1
		self.SetOpenAmount(1)
		self.openCountController.SetSliderPos(0.0)
		self.chestDrop = { }
		self.RefreshItemSlot()
		
		self.SetInvItemSlot(invItemPos)
	
		self.SetTop()
		self.SetCenterPosition()
		self.Show()

	def SetItemToolTip(self, tooltip):
		self.tooltipItem = tooltip
		
	def OnChangeOpenAmount(self):
		openTemp = int(self.openCountController.GetSliderPos() * 10)
		if openTemp == 0:
			self.SetOpenAmount(1)
		else:
			self.SetOpenAmount(openTemp)
			
	def AddChestDropItem(self, chestVnum, pageIndex, slotIndex, itemVnum, itemCount):
		if not self.chestDrop.has_key(chestVnum):
			self.chestDrop[chestVnum] = {}
			
		if not self.chestDrop[chestVnum].has_key(pageIndex):
			self.chestDrop[chestVnum][pageIndex] = {}
	
		if self.chestDrop[chestVnum].has_key(pageIndex):
			if self.chestDrop[chestVnum][pageIndex].has_key(slotIndex):
				if self.chestDrop[chestVnum][pageIndex][slotIndex][0] == itemVnum and self.chestDrop[chestVnum][pageIndex][slotIndex][1] == itemCount:
					return

		self.chestDrop[chestVnum][pageIndex][slotIndex] = [itemVnum, itemCount]

	def OnClickOpenChest(self):
		if self.invItemPos == -1:
			return
			
		itemCount = player.GetItemCount(self.invItemPos)

	#	if player.GetItemTypeBySlot(self.invItemPos) == item.ITEM_TYPE_GACHA:
	#		itemCount = player.GetItemMetinSocket(player.INVENTORY, self.invItemPos, 0)
			
		if itemCount >= self.openAmount:
			for i in xrange(self.openAmount):
				if itemCount == 1:
					net.SendItemUsePacket(self.invItemPos)
					self.OnPressEscapeKey()
					break
					
				net.SendItemUsePacket(self.invItemPos)
				itemCount = itemCount - 1
		else:
			for i in xrange(itemCount):
				if itemCount == 1:
					net.SendItemUsePacket(self.invItemPos)
					self.OnPressEscapeKey()
					break
					
				net.SendItemUsePacket(self.invItemPos)
				itemCount = itemCount - 1
					
	def OnClickPrevPage(self):
		if not self.chestDrop.has_key(self.currentChest):
			return
			
		if self.chestDrop[self.currentChest].has_key(self.currentPage - 1):
			self.currentPage = self.currentPage - 1
			self.currentPageText.SetText(str(self.currentPage))
			self.RefreshItemSlot()
		
	def OnClickNextPage(self):
		if not self.chestDrop.has_key(self.currentChest):
			return
			
		if self.chestDrop[self.currentChest].has_key(self.currentPage + 1):
			self.currentPage = self.currentPage + 1
			self.currentPageText.SetText(str(self.currentPage))
			self.RefreshItemSlot()
			
	def EnableMultiPage(self):
		self.openChestButtonSingle.Hide()
		self.openChestButtonMultiple.Show()
		
		self.prevButton.Show()
		self.nextButton.Show()
		self.currentPageBack.Show()
		
	def EnableSinglePage(self):
		self.openChestButtonSingle.Show()
		self.openChestButtonMultiple.Hide()
		
		self.prevButton.Hide()
		self.nextButton.Hide()
		self.currentPageBack.Hide()	
		
	def SetInvItemSlot(self, invItemPos):
		self.invItemPos = invItemPos
		
		itemVnum = player.GetItemIndex(invItemPos)
		itemCount = player.GetItemCount(invItemPos)
		if itemVnum:
			self.openItemSlot.SetItemSlot(0, itemVnum, itemCount)
			
	def GetInvItemSlot(self):
		return self.invItemPos
			
	def RefreshItems(self, chestVnum):
		if chestVnum:
			self.currentChest = chestVnum
			
		if not self.chestDrop.has_key(self.currentChest):
			chat.AppendChat(chat.CHAT_TYPE_INFO, "Acest cufar nu are drop. Raporteaza probleme unui administrator.")
			self.Close()
			return
			
		if self.chestDrop[self.currentChest].has_key(2):
			self.EnableMultiPage()
		else:
			self.EnableSinglePage()
			
		self.RefreshItemSlot()

	def RefreshItemSlot(self):
		for i in xrange(15 * 5):
			self.wndItem.ClearSlot(i)
			
		if not self.chestDrop.has_key(self.currentChest):
			return
			
		if not self.chestDrop[self.currentChest].has_key(self.currentPage):
			return
			
		for key, value in self.chestDrop[self.currentChest][self.currentPage].iteritems():
			itemVnum = value[0]
			itemCount = value[1]

			if itemCount <= 1:
				itemCount = 0
			
			self.wndItem.SetItemSlot(key, itemVnum, itemCount)
			
		wndMgr.RefreshSlot(self.wndItem.GetWindowHandle())
			
	def OverInItem(self, slotIndex):
		if mouseModule.mouseController.isAttached():
			return
			
		if not self.chestDrop.has_key(self.currentChest):
			return
			
		if not self.chestDrop[self.currentChest].has_key(self.currentPage):
			return
    
		if 0 != self.tooltipItem:
			self.tooltipItem.SetItemToolTip(self.chestDrop[self.currentChest][self.currentPage][slotIndex][0])
    
	def OverOutItem(self):
		if 0 != self.tooltipItem:
			self.tooltipItem.HideToolTip()
								
	def OnPressEscapeKey(self):
		self.Close()
		return True

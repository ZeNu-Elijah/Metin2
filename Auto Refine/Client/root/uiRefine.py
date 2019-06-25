## 0.1 Search:

		self.titleBar.SetCloseEvent(ui.__mem_func__(self.CancelRefine))
		
	
## 0.1 Add after:

		if app.ENABLE_REFINE_RENEWAL:
			self.checkBox = ui.CheckBox()
			self.checkBox.SetParent(self)
			self.checkBox.SetPosition(0, 90)
			self.checkBox.SetWindowHorizontalAlignCenter()
			self.checkBox.SetWindowVerticalAlignBottom()
			self.checkBox.SetEvent(ui.__mem_func__(self.AutoRefine), "ON_CHECK", True)
			self.checkBox.SetEvent(ui.__mem_func__(self.AutoRefine), "ON_UNCKECK", False)
			self.checkBox.SetCheckStatus(constInfo.IS_AUTO_REFINE)
			self.checkBox.SetTextInfo("Pastreaza fereastra deschisa")
			self.checkBox.Show()
			
			
## 0.2 Search :

	def Destroy(self):
			..
			
## 0.2 Add after:

	if app.ENABLE_REFINE_RENEWAL:
		def __InitializeOpen(self):
			self.children = []
			self.vnum = 0
			self.targetItemPos = 0
			self.dialogHeight = 0
			self.cost = 0
			self.percentage = 0
			self.type = 0
			self.xRefineStart = 0
			self.yRefineStart = 0	
			
			
## 0.3 In def Open(self, targetItemPos, nextGradeItemVnum, cost, prob, type):
#Search :
		self.__Initialize()
		
## 0.3 Replace with :

		if app.ENABLE_REFINE_RENEWAL:
			self.__InitializeOpen()
		else:
			self.__Initialize()
			
	
## 0.4 Search in : def UpdateDialog(self):

#		newHeight = self.dialogHeight + <your value>  add + 10 ...



## 0.5 Search :

	def Accept(self):
		..
		
## 0.5 Replace with :

	def Accept(self):
		if app.ENABLE_REFINE_RENEWAL:
			net.SendRefinePacket(self.targetItemPos, self.type)
		else:
			net.SendRefinePacket(self.targetItemPos, self.type)
			self.Close()
			
		
## 0.6 Search:

	def CancelRefine(self):
		...
		
## 0.6 Replace with :

	def CancelRefine(self):
		net.SendRefinePacket(255, 255)
		self.Close()
		
		if app.ENABLE_REFINE_RENEWAL:
			constInfo.AUTO_REFINE_TYPE = 0
			constInfo.AUTO_REFINE_DATA = {
				"ITEM" : [-1, -1],
				"NPC" : [0, -1, -1, 0]
			}
			
	
## 0.7 Search again for def Accept :
## 0.7 Add after :
	if app.ENABLE_REFINE_RENEWAL:	
		def AutoRefine(self, checkType, autoFlag):
			constInfo.IS_AUTO_REFINE = autoFlag
		
		def CheckRefine(self, isFail):
			if constInfo.IS_AUTO_REFINE == True:
				if constInfo.AUTO_REFINE_TYPE == 1:
					if constInfo.AUTO_REFINE_DATA["ITEM"][0] != -1 and constInfo.AUTO_REFINE_DATA["ITEM"][1] != -1:
						scrollIndex = player.GetItemIndex(constInfo.AUTO_REFINE_DATA["ITEM"][0])
						itemIndex = player.GetItemIndex(constInfo.AUTO_REFINE_DATA["ITEM"][1])
						
						chat.AppendChat(chat.CHAT_TYPE_INFO, "%d %d" % (itemIndex, int(itemIndex %10)))
						if scrollIndex == 0 or (itemIndex % 10 == 8 and not isFail):
							self.Close()
						else:
							net.SendItemUseToItemPacket(constInfo.AUTO_REFINE_DATA["ITEM"][0], constInfo.AUTO_REFINE_DATA["ITEM"][1])
				elif constInfo.AUTO_REFINE_TYPE == 2:
					npcData = constInfo.AUTO_REFINE_DATA["NPC"]
					if npcData[0] != 0 and npcData[1] != -1 and npcData[2] != -1 and npcData[3] != 0:
						itemIndex = player.GetItemIndex(npcData[1], npcData[2])
						if (itemIndex % 10 == 8 and not isFail) or isFail:
							self.Close()
						else:
							net.SendGiveItemPacket(npcData[0], npcData[1], npcData[2], npcData[3])
				else:
					self.Close()
			else:
				self.Close()
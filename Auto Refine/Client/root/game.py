## 0.1 Search:


	def RefineSuceededMessage(self):
		...
		

## 0.1 Replace with :

	def RefineSuceededMessage(self):
		self.PopupMessage(localeInfo.REFINE_SUCCESS)
		if app.ENABLE_REFINE_RENEWAL:
			self.interface.CheckRefineDialog(False)
			
			
## 0.2 Search:


	def RefineFailedMessage(self):
		...
		

## 0.2 Replace with :

	def RefineFailedMessage(self):
		self.PopupMessage(localeInfo.REFINE_FAILURE)
		if app.ENABLE_REFINE_RENEWAL:
			self.interface.CheckRefineDialog(True)
			
			
## 0.3 In function def __PutItem(self,  ....
# Search :

				if chr.IsNPC(dstChrID):
		
## 0.3 Add after :

					if app.ENABLE_REFINE_RENEWAL:
						constInfo.AUTO_REFINE_TYPE = 2
						constInfo.AUTO_REFINE_DATA["NPC"][0] = dstChrID
						constInfo.AUTO_REFINE_DATA["NPC"][1] = attachedInvenType
						constInfo.AUTO_REFINE_DATA["NPC"][2] = attachedItemSlotPos
						constInfo.AUTO_REFINE_DATA["NPC"][3] = attachedItemCount

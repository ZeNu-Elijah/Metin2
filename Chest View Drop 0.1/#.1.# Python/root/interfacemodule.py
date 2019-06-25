## 1. Search:
import net
## 1. Add after:
if app.ENABLE_SHOW_CHEST_DROP:
	import uiChestDrop
	
## 2. Search:
		self.wndGuild = None
		self.wndGuildBuilding = None
## 2. Add after:
		if app.ENABLE_SHOW_CHEST_DROP:
			self.dlgChestDrop = None
			
			
## 3. Search:		
		self.wndChatLog = wndChatLog
## 3. Add after:
		if app.ENABLE_SHOW_CHEST_DROP:
			self.dlgChestDrop = uiChestDrop.ChestDropWindow()
			
			
## 4. Search:
		self.wndItemSelect.SetItemToolTip(self.tooltipItem)
## 4. Add after:
		if app.ENABLE_SHOW_CHEST_DROP:
			self.dlgChestDrop.SetItemToolTip(self.tooltipItem)
		
		
## 5. Search:		
		if self.mallPageDlg:
			self.mallPageDlg.Destroy()
## 5. Add after:
		if app.ENABLE_SHOW_CHEST_DROP:
			if self.dlgChestDrop:
				self.dlgChestDrop.Destroy()

				
## 6. Search:
		del self.wndItemSelect
		del self.bigBoardControl
## 6. Add after:
		if app.ENABLE_SHOW_CHEST_DROP:
			if self.dlgChestDrop:
				del self.dlgChestDrop
			
			
## 7. Search:
	def RefreshShopDialog(self):
		self.dlgShop.Refresh()
## 7. Add after:
	if app.ENABLE_SHOW_CHEST_DROP:
		def AddChestDropInfo(self, chestVnum, pageIndex, slotIndex, itemVnum, itemCount):
			self.dlgChestDrop.AddChestDropItem(int(chestVnum), int(pageIndex), int(slotIndex), int(itemVnum), int(itemCount))
			
		def RefreshChestDropInfo(self, chestVnum):
			self.dlgChestDrop.RefreshItems(chestVnum)
			
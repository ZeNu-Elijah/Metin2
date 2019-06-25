## 1. In function:
	def __UseItem(self, slotIndex):
## 1. Before:
		else:
			self.__SendUseItemPacket(slotIndex)
## 1. Add:
		#elif player.GetItemTypeBySlot(slotIndex) == item.ITEM_TYPE_GACHA or player.GetItemTypeBySlot(slotIndex) == item.ITEM_TYPE_GIFTBOX:

		elif player.GetItemTypeBySlot(slotIndex) == item.ITEM_TYPE_GIFTBOX:
			if app.ENABLE_SHOW_CHEST_DROP:
				if self.interface:
					if self.interface.dlgChestDrop:
						if not self.interface.dlgChestDrop.IsShow():
							self.interface.dlgChestDrop.Open(slotIndex)
							net.SendChestDropInfo(slotIndex)
## 0.1 Search:

		if player.REFINE_OK != player.CanRefine(scrollIndex, targetSlotPos):
			return

## 0.1 Add after:

		if app.ENABLE_REFINE_RENEWAL:
			constInfo.AUTO_REFINE_TYPE = 1
			constInfo.AUTO_REFINE_DATA["ITEM"][0] = scrollSlotPos
			constInfo.AUTO_REFINE_DATA["ITEM"][1] = targetSlotPos
		
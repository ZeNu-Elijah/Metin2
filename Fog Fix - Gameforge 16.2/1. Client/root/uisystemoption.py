### 1. Search:
		self.__Load()
### 1. Add after:
		if app.ENABLE_FOG_FIX:
			self.RefreshFogMode()
			
			
### 2. Search:
			self.fogModeButtonList.append(GetObject("fog_level0"))
			self.fogModeButtonList.append(GetObject("fog_level1"))
			self.fogModeButtonList.append(GetObject("fog_level2"))
### 2. Replace with:
			if app.ENABLE_FOG_FIX:
				self.fogModeButtonList.append(GetObject("fog_on"))
				self.fogModeButtonList.append(GetObject("fog_off"))
			else:
				self.fogModeButtonList.append(GetObject("fog_level0"))
				self.fogModeButtonList.append(GetObject("fog_level1"))
				self.fogModeButtonList.append(GetObject("fog_level2"))
				
				
### 3. Search:
		self.fogModeButtonList[0].SAFE_SetEvent(self.__OnClickFogModeLevel0Button)
		self.fogModeButtonList[1].SAFE_SetEvent(self.__OnClickFogModeLevel1Button)
		self.fogModeButtonList[2].SAFE_SetEvent(self.__OnClickFogModeLevel2Button)
### 3. Replace with:
		if app.ENABLE_FOG_FIX:
			self.fogModeButtonList[0].SAFE_SetEvent(self.__OnClickFogModeOn)
			self.fogModeButtonList[1].SAFE_SetEvent(self.__OnClickFogModeOff)
		else:
			self.fogModeButtonList[0].SAFE_SetEvent(self.__OnClickFogModeLevel0Button)
			self.fogModeButtonList[1].SAFE_SetEvent(self.__OnClickFogModeLevel1Button)
			self.fogModeButtonList[2].SAFE_SetEvent(self.__OnClickFogModeLevel2Button)
			
			
### 4. Search:
		self.__ClickRadioButton(self.fogModeButtonList, constInfo.GET_FOG_LEVEL_INDEX())
### 4. Replace with:
		if not app.ENABLE_FOG_FIX:
			self.__ClickRadioButton(self.fogModeButtonList, constInfo.GET_FOG_LEVEL_INDEX())
			
			
### 5. Search:
	def OnChangeShadowQuality(self):
		pos = self.ctrlShadowQuality.GetSliderPos()
		systemSetting.SetShadowLevel(int(pos / 0.2))
### 5. Add after:
	if app.ENABLE_FOG_FIX:
		def __OnClickFogModeOn(self):
			systemSetting.SetFogMode(True)
			background.SetEnvironmentFog(True)
			self.RefreshFogMode()
			
		def __OnClickFogModeOff(self):
			systemSetting.SetFogMode(False)
			background.SetEnvironmentFog(False)
			self.RefreshFogMode()
			
		def RefreshFogMode(self):
			if systemSetting.IsFogMode():
				self.fogModeButtonList[0].Down()
				self.fogModeButtonList[1].SetUp()
			else:
				self.fogModeButtonList[0].SetUp()
				self.fogModeButtonList[1].Down()
			
			
			
			
			
			
			
			
			
			
			
			
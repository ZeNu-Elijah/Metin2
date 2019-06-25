### 1. Search:
		self.currentCubeNPC = 0
### 1. Add after:	
		if app.ENABLE_FOG_FIX:
			if systemSetting.IsFogMode():
				background.SetEnvironmentFog(True)
			else:
				background.SetEnvironmentFog(False)	
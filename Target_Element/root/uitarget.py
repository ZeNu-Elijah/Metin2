## Search:
		hpGauge.Hide()
## Add after:
		elementImage = ui.ImageBox()
		elementImage.SetParent(self)
		elementImage.Hide()

		
## Search:	
		self.hpGauge = hpGauge
## Add after:
		self.elementImage = elementImage
		
	
## Search:
		self.hpGauge = None
## Add after:
		self.elementImage = None
		
		
## Search:
		self.hpGauge.Hide()
## Add after:
		self.elementImage.Hide()
		
		
## Search:		
	def SetEnemyVID(self, vid):
		self.SetTargetVID(vid)
## Replace with:
	def SetEnemyVID(self, vid):
		self.SetTargetVID(vid)
		self.SetRaceElement(vid)
		
		
## Search:		
		self.SetTargetName(nameFront + name)
## Add after:
	def SetRaceElement(self, vid):
		flagList = {
			"ATT_ELEC" : "elect", 
			"ATT_FIRE" : "fire",
			"ATT_ICE" : "ice",
			"ATT_WIND" : "wind",
			"ATT_EARTH" : "earth",
			"ATT_DARK" : "dark"
		}
		
		vnum = nonplayer.GetVnumByVID(vid)
		hasElement = False
		elementName = ""
		
		if vnum != 0:
			for key, value in flagList.iteritems():
				if nonplayer.MonsterHasRaceFlag(vnum, key):
					hasElement = True
					elementName = key
					break
			
		if vnum != 0 and hasElement == True:
			self.elementImage.LoadImage("d:/ymir work/ui/game/12zi/element/%s.sub" % (flagList[elementName]))
			self.elementImage.SetPosition(-self.elementImage.GetWidth(), 0)
			self.elementImage.Show()
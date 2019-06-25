## 0.1 Search :

	def RefineBindAffectShower(self, affectShower):
				...
				
				
## 0.1 Add after:


	if app.ENABLE_REFINE_RENEWAL:
		def CheckRefineDialog(self, isFail):
			self.dlgRefineNew.CheckRefine(isFail)
			
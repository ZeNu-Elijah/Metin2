# ADD THIS AFTER SOME IMPORT :

if app.ENABLE_MOVE_CHANNEL:
	import chat,serverInfo,net,ServerStateChecker
	
# Search :
		self.gameOptionDlg = None
		
# Add after :
		if app.ENABLE_MOVE_CHANNEL:
			self.moveChannelDlg = None
			
			
# Search :
		self.GetChild("cancel_button").SAFE_SetEvent(self.Close)
		
# Add after :
		if app.ENABLE_MOVE_CHANNEL:
			self.GetChild("movechannel_button").SAFE_SetEvent(self.__ClickMoveChannel)
			
			
# Search :
		if self.systemOptionDlg:
			self.systemOptionDlg.Destroy()
		
# Add after :
		if app.ENABLE_MOVE_CHANNEL:
			if self.moveChannelDlg:
				self.moveChannelDlg.Destroy()
			
			
# Search :
	def __ClickGameOptionButton(self):
		self.Close()

		if not self.gameOptionDlg:
			self.gameOptionDlg = uiGameOption.OptionDialog()
			self.gameOptionDlg.BindInterface(self.interface)	

		self.gameOptionDlg.Show()
		
# Add after :
	if app.ENABLE_MOVE_CHANNEL:
		def __ClickMoveChannel(self):
			self.Close()
			if not self.moveChannelDlg:
				self.moveChannelDlg = MoveChannelWindow()
	
			self.moveChannelDlg.Show()
				
		
########################################### ADD THIS ON THE END OF FILE ##########################################################
class MoveChannelWindow(ui.ScriptWindow):
	def __init__(self):
		ui.ScriptWindow.__init__(self)
		self.titleBar = None
		ServerStateChecker.Create(self)
		self.channelButtonList = []
		self.currentChannel = 0
		self.__LoadBoard()
		self.RefreshChannelButtons()
		self.Show()
		self.SetCenterPosition()
		self.RefreshBeforeShow()

	def __del__(self):
		ui.ScriptWindow.__del__(self)

	def __LoadBoard(self):
		try:
			pyScrLoader = ui.PythonScriptLoader()
			pyScrLoader.LoadScriptFile(self, "UIScript/MoveChannelDialog.py")
		except:
			import exception
			exception.Abort("MoveChannelWindow.__LoadBoard.LoadScript")

		try:
			self.board = self.GetChild("MoveChannelBoard")
			self.titleBar = self.GetChild("MoveChannelTitle")
			self.blackBoard = self.GetChild("BlackBoard")
			self.okButton = self.GetChild("AcceptButton")
			self.cancelButton = self.GetChild("CancelButton")
		except:
			import exception
			exception.Abort("MoveChannelWindow.__LoadBoard.BindObject")

		self.titleBar.SetCloseEvent(ui.__mem_func__(self.Close))
		self.okButton.SetEvent(ui.__mem_func__(self.ChangeChannel))
		self.cancelButton.SetEvent(ui.__mem_func__(self.Close))
		self.SetCurentChannel()
		self.AddChannels()
		
	def SetCurentChannel(self):
		try:
			self.currentChannel = int( int(net.GetServerInfo().split(",")[1][-1:]) - 1 )
		except:
			return
		
	def __GetServerID(self):
		for i in serverInfo.REGION_DICT[0].keys():
			if serverInfo.REGION_DICT[0][i]["name"] == net.GetServerInfo().split(",")[0]:
				serverID = int(i)
				break

		return serverID
		
	def __GetChannelNumber(self):
		serverID = self.__GetServerID()
		try:
			channelDict = serverInfo.REGION_DICT[0][serverID]["channel"]
		except:
			return
			
		return len(channelDict)	
		
	def RefreshBeforeShow(self):
		self.__RequestServerStateList()

	def __RequestServerStateList(self):
		try:
			channelDict = serverInfo.REGION_DICT[0][self.__GetServerID()]["channel"]
		except:
			return
		
		ServerStateChecker.Initialize(self)
		for id, channelDataDict in channelDict.items():
			key = channelDataDict["key"]
			ip = channelDataDict["ip"]
			udp_port = channelDataDict["udp_port"]
			ServerStateChecker.AddChannel(key, ip, udp_port)
		ServerStateChecker.Request()

	def NotifyChannelState(self, addrKey, state):
		try:
			stateName = serverInfo.STATE_DICT[state]
		except:
			stateName = serverInfo.STATE_NONE
		
		regionID  = int(addrKey / 1000)
		serverID  = int(addrKey / 10) % 100
		channelID = addrKey % 10
		try:
			serverInfo.REGION_DICT[regionID][serverID]["channel"][channelID]["state"] = stateName
			self.__RefreshChannelStateList()
		except:
			pass

	def AddChannels(self):				
		self.SetSize(190,80+30*self.__GetChannelNumber())
		self.board.SetSize(190,80+30*self.__GetChannelNumber())
		self.blackBoard.SetSize(163,7+30*self.__GetChannelNumber())
		
		for i in xrange(self.__GetChannelNumber()):
			self.channelButtonList.append(ui.MakeRadioButton(self.blackBoard, 7, 7+30*i, "d:/ymir work/ui/game/myshop_deco/", "select_btn_01.sub", "select_btn_02.sub", "select_btn_03.sub"))
			self.channelButtonList[i].SetText(str(serverInfo.REGION_DICT[0][self.__GetServerID()]["channel"][i+1]["name"]))
			self.channelButtonList[i].SetEvent(lambda arg=i: self.SelectChannel(arg))
			self.channelButtonList[i].Show()	
			
			
	def SelectChannel(self,channel):
		self.currentChannel = channel
		self.RefreshChannelButtons()
				
	def RefreshChannelButtons(self):
		for i in xrange(self.__GetChannelNumber()):
			if i == self.currentChannel:
				self.channelButtonList[i].Down()
			else:
				self.channelButtonList[i].SetUp()
		
	def ChangeChannel(self):
		ServerStateChecker.Update()
		channelID = self.currentChannel+1
		channelState = serverInfo.REGION_DICT[0][self.__GetServerID()]["channel"][channelID]["state"]
		if not channelID:
			return
		
		if channelState == serverInfo.STATE_NONE or channelState == serverInfo.STATE_DICT[0]:
			chat.AppendChat(chat.CHAT_TYPE_INFO , "Acest canal este offline")
			return
			
		self.Close()
		net.SendChatPacket("/change_channel " + str(channelID))
				
	def Destroy(self):
		self.ClearDictionary()
		self.Hide()
		
	def Close(self):
		ServerStateChecker.Initialize(self)
		self.Hide()
		
	def OnUpdate(self):
		ServerStateChecker.Update()
		
	def OnPressEscapeKey(self):
		self.Close()
		return True
		
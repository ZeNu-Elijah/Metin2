## Search:
	def __LoverDivorce(self):
		if self.interface.wndMessenger:
			self.interface.wndMessenger.ClearLoverInfo()
		if self.affectShower:
			self.affectShower.ClearLoverState()

## Add after:

	if app.ENABLE_MOVE_CHANNEL:
		def __GetServerID(self):
			serverID = 1
			for i in serverInfo.REGION_DICT[0].keys():
				if serverInfo.REGION_DICT[0][i]["name"] == net.GetServerInfo().split(",")[0]:
					serverID = int(i)
					break
	
			return serverID
		
		def RefreshChannel(self, channel):
			channelName = ""
			serverName = serverInfo.REGION_DICT[0][self.__GetServerID()]["name"]
			if channel in serverInfo.REGION_DICT[0][self.__GetServerID()]["channel"]:
				channelName = serverInfo.REGION_DICT[0][self.__GetServerID()]["channel"][int(channel)]["name"]
			elif channel == 99:
				channelName = "Special CH"
			else:
				channelName = "Unknow CH"
				
			net.SetServerInfo("%s, %s" % (serverName,channelName))
			if self.interface:
				self.interface.wndMiniMap.serverInfo.SetText(net.GetServerInfo())
				
			chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.MOVE_CHANNEL_NOTICE % (channel))
				
			app.ChangeTitle(net.GetServerInfo())
			
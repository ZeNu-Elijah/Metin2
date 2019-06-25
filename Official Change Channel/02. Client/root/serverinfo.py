####### IF U WANT THIS SHIT,

###################### SMALL RENEWAL OF SERVER INFO ###################




import app
import localeInfo
app.ServerName = None

SRV1 = {
	"name":"Anchor2 - Live",
	"host":"188.212.103.10",
	"auth1":31311,
	"ch1":30001,
	"ch2":30101,
	"ch3":30201,
	"ch4":30301,
	"ch5":30401,
	"ch6":30501,
}

SRV_TESTE = {
	"name":"Anchor2 - Test",
	"host":"188.212.103.4",
	"auth1":31309,
	"ch1":30001,
	"ch2":30101,
	"ch3":30201,
	"ch4":30301,
	"ch5":30401,
	"ch6":30501,
}

STATE_NONE = "...."

STATE_DICT = {
	0 : "....",
	1 : "NORM",
	2 : "BUSY",
	3 : "FULL"
}

STATE_DICT_NAME = {
	"...." : "Offline",
	"NORM" : "Normal",
	"BUSY" : "Ocupat",
	"FULL" : "Plin"
}

STATE_DICT_IMAGES = {
	"...." : "channel_offline.tga",
	"NORM" : "channel_normal.tga",
	"BUSY": "channel_busy.tga",
	"FULL" : "channel_full.tga"
}

we = {
	1:{"key":11,"name":"Channel 1","ip":SRV1["host"],"tcp_port":SRV1["ch1"],"udp_port":SRV1["ch1"],"state":STATE_NONE,},
	2:{"key":12,"name":"Channel 2","ip":SRV1["host"],"tcp_port":SRV1["ch2"],"udp_port":SRV1["ch2"],"state":STATE_NONE,},
	3:{"key":13,"name":"Channel 3","ip":SRV1["host"],"tcp_port":SRV1["ch3"],"udp_port":SRV1["ch3"],"state":STATE_NONE,},
	4:{"key":14,"name":"Channel 4","ip":SRV1["host"],"tcp_port":SRV1["ch4"],"udp_port":SRV1["ch4"],"state":STATE_NONE,},
}

we_teste = {
	1:{"key":21,"name":"Channel 1","ip":SRV_TESTE["host"],"tcp_port":SRV_TESTE["ch1"],"udp_port":SRV_TESTE["ch1"],"state":STATE_NONE,},
	2:{"key":22,"name":"Channel 2","ip":SRV_TESTE["host"],"tcp_port":SRV_TESTE["ch2"],"udp_port":SRV_TESTE["ch2"],"state":STATE_NONE,},
	3:{"key":23,"name":"Channel 3","ip":SRV_TESTE["host"],"tcp_port":SRV_TESTE["ch3"],"udp_port":SRV_TESTE["ch3"],"state":STATE_NONE,},
	4:{"key":24,"name":"Channel 4","ip":SRV_TESTE["host"],"tcp_port":SRV_TESTE["ch4"],"udp_port":SRV_TESTE["ch4"],"state":STATE_NONE,},
}

REGION_NAME_DICT = {
	0 : SRV1["name"],
	1 : SRV_TESTE["name"],
}

REGION_AUTH_SERVER_DICT = {
	0 : {
		1 : { "ip":SRV1["host"], "port":SRV1["auth1"], },
		2 : { "ip":SRV_TESTE["host"], "port":SRV_TESTE["auth1"], },
	}
}

REGION_DICT = {
	0 : {
		1 : { "name" :SRV1["name"], "channel" : we, },
		2 : { "name" :SRV_TESTE["name"], "channel" : we_teste, },
	},
}

MARKADDR_DICT = {
	10 : { "ip" : SRV1["host"], "tcp_port" : SRV1["ch1"], "mark" : "10.tga", "symbol_path" : "10", },
	11 : { "ip" : SRV1["host"], "tcp_port" : SRV1["ch2"], "mark" : "10.tga", "symbol_path" : "11", },
	12 : { "ip" : SRV1["host"], "tcp_port" : SRV1["ch3"], "mark" : "10.tga", "symbol_path" : "12", },
	13 : { "ip" : SRV1["host"], "tcp_port" : SRV1["ch4"], "mark" : "10.tga", "symbol_path" : "13", },
	14 : { "ip" : SRV1["host"], "tcp_port" : SRV1["ch5"], "mark" : "10.tga", "symbol_path" : "14", },
	15 : { "ip" : SRV1["host"], "tcp_port" : SRV1["ch6"], "mark" : "10.tga", "symbol_path" : "15", },
	20 : { "ip" : SRV_TESTE["host"], "tcp_port" : SRV_TESTE["ch1"], "mark" : "10.tga", "symbol_path" : "10", },
}

TESTADDR = { "ip" : SRV1["host"], "tcp_port" : SRV1["ch1"], "udp_port" : SRV1["ch1"], }



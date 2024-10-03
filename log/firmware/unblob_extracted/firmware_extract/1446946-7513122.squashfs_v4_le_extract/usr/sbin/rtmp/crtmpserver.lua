configuration=
{
	daemon=true,
	pathSeparator="/",

	logAppenders=
	{
		{
			name="console appender",
			type="coloredConsole",
			level=0
		},
		{
			name="file appender",
			type="file",
			level=0,
			fileName="/var/log/crtmpserver.log",
			--newLineCharacters="\r\n",
			fileHistorySize=10,
			fileLength=1024*256,
			singleLine=true
		}
	},
	
	-- this node holds all the RTMP applications
	applications=
	{
		rootDirectory="applications",
		{
			name="appselector",
			description="Application for selecting the rest of the applications",
			protocol="dynamiclinklibrary",
			validateHandshake=true,
			default=true,
			acceptors = 
			{
				{
					ip="0.0.0.0",
					port=1935,
					protocol="inboundRtmp"
				},
			}
		},
		{
			description="FLV Playback Sample",
			name="flvplayback",
			protocol="dynamiclinklibrary",
			mediaFolder="/mnt/storage/dcs-960l",
			aliases=
			{
				"simpleLive",
				"vod",
				"live",
				"WeeklyQuest",
				"SOSample",
				"oflaDemo",
			},
			externalStreams = 
			{
				{
					uri="rtsp://admin:@127.0.0.1:554/play1.sdp",
					localStreamName="rtsp_relay",
					forceTcp=true
				}
			},
			validateHandshake=true,
			keyframeSeek=true,
			seekGranularity=1.5, --in seconds, between 0.1 and 600
			clientSideBuffer=12, --in seconds, between 5 and 30
			--generateMetaFiles=true, --this will generate seek/meta files on application startup
			--renameBadFiles=false,
			enableCheckBandwidth=true,

			-- modify for force auth, publish and override jimmy.kao 20150803
			--[[ comment for recall
				If forceAuth equals false, then the auth relys on encoderAgents.
				The agents inside the list will be authenticated, others can access directly.
			]]--
			autoReconn=true,
			forceAuth=true,
			enablePublish=false,					-- enable publish for 2 way audio through rtmp protocol
			enableOverrideStreamName=false,
			authentication=
			{
				rtmp={
					type="adobe",
					encoderAgents=
					{
						"FMLE/3.0 (compatible; FMSc/1.0)",
						"crtmpserver",
					},
					--[[
						If userFiles equals userconfig, then server uses ip camera system user configuration.
						Otherwise, it uses the config file.
					]]--
					usersFile="userconfig"		--use ip camera user config
					--usersFile=".users.lua"	--use .user.lua config
				},
				--[[rtsp={
					usersFile="users.lua"
				}]]--
			},

		},
	}
}


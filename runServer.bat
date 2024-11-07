@echo off

taskkill /im DayZServer_x64.exe /F

set serverName=My Server
set serverLocation="C:\Program Files (x86)\Steam\steamapps\common\DayZServer"
set serverPort=2302
set serverConfig=serverConfig.cfg
set serverCPU=2

title %serverName% batch
cd "%serverLocation%"
echo (%time%) %serverName% started.

start "DayZ Server" /min "DayZServer_x64.exe" "-mod=@IVB;@CF;@VPPAdminTools" -config=%serverConfig% -port=%serverPort% -cpuCount=%serverCPU% -dologs -adminlog -netlog -freezecheck  -profiles=myServer-1

timeout 25

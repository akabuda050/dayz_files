@echo off

taskkill /im DayZServer_x64.exe /F

set serverName=IdlePoint PVP/PVE
set serverPath=C:\Program Files (x86)\Steam\steamapps\common\DayZServer
set serverPort=2302
set serverCPU=2

title %serverName% batch
echo (%time%) %serverName% started.

timeout 25

set liveServerPath=C:\Users\%USERNAME%\Storage\DayZModding\server\idlepoint_1_live

set serverPath=%liveServerPath%
set missionPath=%serverPath%\mpmissions\dayzOffline.chernarusplus
set configPath=%serverPath%\config.cfg

set profileFolder=%serverPath%\profiles
set profileFolderClient=%serverPath%\profilesClient

set mods=@IVB;@CF;@Community-Online-Tools

echo %dayz%
echo %serverPath%
echo %profileFolderClient%
echo %configPath%

del "%profileFolder%\*.log"
del "%profileFolder%\*.RPT"
del "%profileFolder%\*.ADM"
del "%profileFolder%\*.mdmp"

timeout 60

start "DayZ Server" /D "%serverPath%" DayZServer_x64.exe "-mod=%mods%" "-mission=%missionPath%" "-config=%configPath%" "-profiles=%profileFolder%" -port=%serverPort% -cpuCount=%serverCPU% -dologs -adminlog -netlog -freezecheck

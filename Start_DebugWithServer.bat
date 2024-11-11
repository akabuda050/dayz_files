@echo off

taskkill /im DayZDiag_x64.exe /F

set charName=Zloipipka

set dayz=C:\Program Files (x86)\Steam\steamapps\common\DayZ
set testingServerPath=C:\Users\%USERNAME%\Storage\DayZModding\server\idlepoint_1_testing
set dayzPDrive=P

set serverPath=%testingServerPath%
set missionPath=%serverPath%\mpmissions\dayzOffline.chernarusplus
set configPath=%serverPath%\config.cfg

set profileFolder=%serverPath%\profiles
set profileFolderClient=%serverPath%\profilesClient

set mods=%dayzPDrive%:\Mods\@IVB;%dayzPath%\!Workshop\@CF;%dayzPath%\!Workshop\@Community-Online-Tools

echo %dayz%
echo %serverPath%
echo %dayzPDrive%
echo %profileFolderClient%
echo %configPath%

del "%profileFolder%\*.log"
del "%profileFolder%\*.RPT"
del "%profileFolder%\*.ADM"
del "%profileFolder%\*.mdmp"
del "%profileFolderClient%\*.log"
del "%profileFolderClient%\*.RPT"
del "%profileFolderClient%\*.ADM"
del "%profileFolderClient%\*.mdmp"

timeout 60

start /D "%dayz%" DayZDiag_x64.exe "-server" "-mod=%mods%" "-mission=%missionPath%" "-config=%configPath%" "-profiles=%profileFolder%" "-limitFPS=1000" "-doLogs" "-newErrorsAreWarnings=1" -forcedebugger -scriptDebug=true -filePatching

timeout 60

start /D "%dayz%" DayZDiag_x64.exe -window "-mod=%mods%" "-profiles=%profileFolderClient%" "-name=%charName%" "-dologs" "-newErrorsAreWarnings=1" -forcedebugger -scriptDebug=true -filePatching -connect=127.0.0.1 -port=2302
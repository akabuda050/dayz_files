@echo off

taskkill /im DayZDiag_x64.exe /F

set charName=Zloipipka

set dayz=C:\Program Files (x86)\Steam\steamapps\common\DayZ
set dayzPDrive=P:

set missionPath=%dayzPDrive%\mpmissions\dayzOffline.chernarusplus
set configPath=%missionPath%\config.cfg

set profileFolder=%dayzPDrive%\mpmissions\dayzOffline.chernarusplus\profiles
set profileFolderClient=%dayzPDrive%\mpmissions\dayzOffline.chernarusplus\profilesClient

set mods=%dayzPDrive%\Mods\@IVB;%dayz%\!Workshop\@CF;%dayz%\!Workshop\@VPPAdminTools

echo %dayz%
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

start ./DayZDiag_x64.exe "-server" "-mod=%mods%" "-config=%configPath%" "-profiles=%profileFolder%" "-limitFPS=1000" "-doLogs" "-newErrorsAreWarnings=1" -forcedebugger -scriptDebug=true -filePatching "-mission=%missionPath%"

timeout 60

start ./DayZDiag_x64.exe -window "-mod=%mods%" "-profiles=%profileFolderClient%" "-name=%charName%" "-dologs" "-newErrorsAreWarnings=1" -forcedebugger -scriptDebug=true -filePatching -connect=127.0.0.1 -port=2302
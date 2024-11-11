@echo off

taskkill /im DayZDiag_x64.exe /F

timeout 25

set dayzPath=C:\Program Files (x86)\Steam\steamapps\common\DayZ
set mission=C:\Users\%USERNAME%\Storage\DayZModding\server\client_debug\mpmissions\clientDebug.ChernarusPlus
set mods=P:\Mods\@IVB;%dayzPath%\!Workshop\@CF;%dayzPath%\!Workshop\@Community-Online-Tools

start /D "%dayzPath%" DayZDiag_x64.exe -window "-mod=%mods%" "-mission=%mission%" -filePatching -dologs -forcedebugger -scriptDebug=true
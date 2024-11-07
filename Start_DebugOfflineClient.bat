@echo off

taskkill /im DayZDiag_x64.exe /F

timeout 25

start ./DayZDiag_x64.exe -window "-mod=P:\Mods\@IVB" "-dologs" "-newErrorsAreWarnings=1" -forcedebugger -scriptDebug=true -filePatching "-mission=P:\mpmissions\firstmission.ChernarusPlus"
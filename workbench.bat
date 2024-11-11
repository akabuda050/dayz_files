@echo off

taskkill /im workbenchApp.exe /F

timeout 5

set dayzToolsPath=C:\Program Files (x86)\Steam\steamapps\common\DayZ Tools\Bin\Workbench
set mods=P:\IVB

start /D "%dayzToolsPath%" workbenchApp.exe "-mod=%mods%"
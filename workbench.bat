@echo off

taskkill /im workbenchApp.exe /F

start /D "C:\Program Files (x86)\Steam\steamapps\common\DayZ Tools\Bin\Workbench" workbenchApp.exe "-mod=P:\IVB"
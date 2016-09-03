@echo off
setlocal EnableDelayedExpansion
set path
set $line=%path%
set $line=%$line: =#%
set $line=%$line:;= %
set $line=%$line:)=^^)%

for %%a in (%$line%) do echo %%a | find /i "Git" || set $newpath=!$newpath!;%%a
set $newpath=!$newpath:#= !
set $newpath=!$newpath:^^=!
set path=!$newpath:~1!

sloeber-ide.exe
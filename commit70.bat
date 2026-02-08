@echo off
setlocal enabledelayedexpansion

set YEAR=2026
set MONTH=02

set COUNT=1
set DAY=8

:loop

if !COUNT! GTR 70 goto end

rem skip some days (gaps)
if !DAY!==12 set /a DAY+=1
if !DAY!==18 set /a DAY+=1
if !DAY!==25 set /a DAY+=1
if !DAY!==32 set /a DAY+=1
if !DAY!==40 set /a DAY+=1
if !DAY!==50 set /a DAY+=1

set DD=!DAY!
if !DD! LSS 10 set DD=0!DD!

echo update !COUNT! >> progress.txt

git add .
git commit --date="%YEAR%-%MONTH%-!DD!T12:00:00" -m "Day !COUNT!"

set /a COUNT+=1
set /a DAY+=1

goto loop

:end

git push --force
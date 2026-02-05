@echo off
setlocal enabledelayedexpansion

set YEAR=2026
set COUNT=41

rem Start from March 1
set MONTH=03
set DAY=1

:loop

if !COUNT! GTR 70 goto end

rem format day
set DD=!DAY!
if !DD! LSS 10 set DD=0!DD!

echo fix !COUNT! >> progress.txt

git add .
git commit --date="%YEAR%-%MONTH%-!DD!T13:00:00" -m "Day !COUNT!"

set /a COUNT+=1
set /a DAY+=1

rem handle month change
if !DAY! GTR 31 (
    set DAY=1
    set /a MONTH+=1
    if !MONTH! LSS 10 set MONTH=0!MONTH!
)

goto loop

:end

git push --force
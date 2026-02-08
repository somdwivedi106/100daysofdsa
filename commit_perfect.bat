@echo off
setlocal enabledelayedexpansion

set YEAR=2026
set MONTH=02
set DAY=8
set COUNT=1

:loop

if !COUNT! GTR 70 goto end

rem skip some days (natural gaps)
if !DAY!==12 set /a DAY+=1
if !DAY!==17 set /a DAY+=1
if !DAY!==23 set /a DAY+=1
if !DAY!==29 set /a DAY+=1

rem format day
set DD=!DAY!
if !DD! LSS 10 set DD=0!DD!

rem format month
set MM=!MONTH!
if !MM! LSS 10 set MM=0!MM!

echo update !COUNT! >> progress.txt

git add .
git commit --date="%YEAR%-%MM%-!DD!T12:00:00" -m "Day !COUNT!"

set /a COUNT+=1
set /a DAY+=1

rem handle month overflow
if !DAY! GTR 28 if !MONTH!==02 (
    set DAY=1
    set MONTH=03
)

if !DAY! GTR 31 if !MONTH!==03 (
    set DAY=1
    set MONTH=04
)

if !DAY! GTR 30 if !MONTH!==04 (
    set DAY=1
    set MONTH=05
)

goto loop

:end

git push --force --set-upstream origin main
@echo off
setlocal enabledelayedexpansion

set YEAR=2026
set MONTH=04

for /l %%i in (1,1,40) do (

    set SKIP=0

    if %%i==7 set SKIP=1
    if %%i==14 set SKIP=1
    if %%i==21 set SKIP=1
    if %%i==29 set SKIP=1

    if !SKIP!==0 (

        set DAY=%%i
        if %%i LSS 10 set DAY=0%%i

        echo update %%i >> progress.txt

        git add .
        git commit --date="%YEAR%-%MONTH%-!DAY!T16:00:00" -m "Day %%i"

    )
)

git push
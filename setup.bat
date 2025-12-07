@echo off
setlocal enabledelayedexpansion

:menu
cls
echo Select the code you want:
echo.
echo 1. bit_stuffing.c
echo 2. char_stuffing.c
echo 3. crc.c
echo 4. distance_vector.c
echo 5. encrypt.c
echo 6. point2point.cc
echo 7. stopNwait.c
echo.

set /p choice=Enter number (1-7): 

if "%choice%"=="1" set file=bit_stuffing.c
if "%choice%"=="2" set file=char_stuffing.c
if "%choice%"=="3" set file=crc.c
if "%choice%"=="4" set file=distance_vector.c
if "%choice%"=="5" set file=encrypt.c
if "%choice%"=="6" set file=point2point.cc
if "%choice%"=="7" set file=stopNwait.c

:: Validate input
if not defined file (
    echo Invalid selection!
    pause
    goto menu
)

echo You selected: %file%
echo.

:: Move selected file to repo root
move /Y "codes\%file%" "%file%" >nul

:: Remove ENTIRE repo except selected file
for /d %%d in (*) do (
    if /I not "%%d"=="." (
        if /I not "%%d"==".." (
            rd /s /q "%%d"
        )
    )
)

for %%f in (*) do (
    if /I not "%%f"=="%file%" (
        del /q "%%f"
    )
)

echo Done!
echo Press any key to exit...
pause >nul
exit

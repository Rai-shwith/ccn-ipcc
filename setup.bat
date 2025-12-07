@echo off
setlocal enabledelayedexpansion

:: Folder where this script lives
set "ROOT=%~dp0"

:: Parent directory (CCN)
for %%A in ("%ROOT%..") do set "PARENT=%%~fA\"

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

set "file="
set /p choice=Enter number (1-7): 

if "%choice%"=="1" set file=bit_stuffing.c
if "%choice%"=="2" set file=char_stuffing.c
if "%choice%"=="3" set file=crc.c
if "%choice%"=="4" set file=distance_vector.c
if "%choice%"=="5" set file=encrypt.c
if "%choice%"=="6" set file=point2point.cc
if "%choice%"=="7" set file=stopNwait.c

if not defined file (
    echo Invalid selection!
    pause
    goto menu
)

echo You selected: %file%
echo.

:: 1. Move chosen code to parent folder (CCN)
move /Y "%ROOT%codes\%file%" "%PARENT%%file%" >nul

:: 2. Move OUT of CCN-ipcc-main folder
pushd "%PARENT%"

:: 3. Delete entire CCN-ipcc-main folder (including codes/)
rd /s /q "%ROOT%"

echo Done!
echo Press any key to exit...
pause >nul
exit

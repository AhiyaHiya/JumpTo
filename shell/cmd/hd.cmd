@echo off

setlocal

REM Add the path to the environment PATH variable
setx PATH "%PATH%;C:\Users\jaime\Development\GitHub\HyperDrive\build\Debug"

REM Check if HyperDrive.exe is available on PATH
@REM where HyperDrive.exe >nul 2>&1
@REM if %errorlevel% neq 0 (
@REM     echo Error: HyperDrive.exe not found on PATH.
@REM     exit /b 1
@REM )

REM Call HyperDrive.exe with the arguments passed to the script
echo WARNING, we are using a path when we should be relying on PATH variable
C:\Users\jaime\Development\GitHub\HyperDrive\build\Debug\HyperDrive.exe %*

endlocal

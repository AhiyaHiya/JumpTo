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

REM Check if the argument is -g or --get
if "%1"=="-g" (
    goto :CallGet
) else if "%1"=="--get" (
    goto :CallGet
) else (
    REM Call HyperDrive.exe with the arguments passed to the script
    C:\Users\jaime\Development\GitHub\HyperDrive\build\Debug\HyperDrive.exe %*
)

goto :EOF

:CallGet
    REM Capture the output of HyperDrive.exe
    for /f "delims=" %%i in ('C:\Users\jaime\Development\GitHub\HyperDrive\build\Debug\HyperDrive.exe %*') do (
        REM Use the output as a path to CD to
        cd /d "%%i"
    )
    exit /b
goto :EOF
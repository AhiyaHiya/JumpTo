@echo off

setlocal

:: Print all arguments passed to the script
echo Arguments: %*

:: Add the path to the environment PATH variable
setx PATH "%PATH%;C:\Users\jaime\Development\GitHub\HyperDrive\build\Debug"

:: Check if HyperDrive.exe is available on PATH
:: where HyperDrive.exe >nul 2>&1
:: if %errorlevel% neq 0 (
::     echo Error: HyperDrive.exe not found on PATH.
::     exit /b 1
:: )

:: Call HyperDrive.exe with the arguments passed to the script
:: echo WARNING, we are using a path when we should be relying on PATH variable

set HyperDrivePath=C:\Users\jaime\Development\GitHub\HyperDrive\build\Debug\HyperDrive.exe

:: Check if the argument is -g or --get
if "%1"=="-g" (
    echo Calling HyperDrive.exe with -g
    goto :CallGet
) else if "%1"=="--get" (
    echo Calling HyperDrive.exe with --get
    goto :CallGet
) else (
    echo Calling HyperDrive.exe with %*
    :: Call HyperDrive.exe with the arguments passed to the script
    %HyperDrivePath% %*
)

goto :EOF

:CallGet
    echo Arguments: %*
    :: Capture the output of HyperDrive.exe
    for /f "delims=" %%i in ('%HyperDrivePath% %*') do (
        :: Use the output as a path to CD to
        echo Changing directory to "%%i"
        cd /d "%%i"
    )
    exit /b
goto :EOF

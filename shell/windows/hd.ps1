# Print all arguments passed to the script
Write-Host "Arguments: $($args -join ' ')"

# Add the path to the environment PATH variable
$env:PATH += ";C:\Users\jaime\Development\GitHub\HyperDrive\build\Debug"

# Check if HyperDrive.exe is available on PATH
if (-not (Get-Command "HyperDrive.exe" -ErrorAction SilentlyContinue)) {
    Write-Host "Error: HyperDrive.exe not found on PATH."
    exit 1
}

# Function to handle the -g or --get argument
function CallGet {
    Write-Host "Arguments: $($args -join ' ')"
    # Capture the output of HyperDrive.exe
    $output = & HyperDrive.exe $args
    # Use the output as a path to CD to
    Write-Host "Changing directory to $output"
    Set-Location -Path $output
}

# Check if the argument is -g or --get
if ($args[0] -eq "-g" -or $args[0] -eq "--get") {
    Write-Host "Calling HyperDrive.exe with $($args[0])"
    CallGet
}
else {
    Write-Host "Calling HyperDrive.exe with $($args -join ' ')"
    # Call HyperDrive.exe with the arguments passed to the script
    & HyperDrive.exe $args
}

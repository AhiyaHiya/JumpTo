Utility app for having fast folder access.

# Setting up a Python virtual environment

This ensures that you are using a specific version of Python.

## Windows

For Python 3.11.x

"C:\Program Files\Python311\python.exe" -m venv NAME_OF_VIRTUAL_FOLDER
NAME_OF_VIRTUAL_FOLDER\Scripts\activate.bat
python --version
conan --version

# How to build

## macOS
python  -m venv conan2_venv
source conan2_venv/bin/activate
python -m pip install conan
conan install ./conan/conanfile.txt --build=missing --output-folder=./ --settings build_type=Debug

cmake -G "Xcode" -DCMAKE_BUILD_TYPE=Debug -B ./build -S .

## Windows
conan install ./conan/conanfile.txt --build=missing --output-folder=./ --profile=./conan/windows.txt --settings build_type=Debug

cmake -G "Visual Studio 17 2022" -DCMAKE_BUILD_TYPE=Debug -B ./build -S .
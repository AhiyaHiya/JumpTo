# Utility app for having fast folder access.

Helper app that is used in conjunction with you shell environment.
The resulting CLI is meant to be a fast mechanism for storing key-value
pairs in a fast datastore, which returns the path of a folder you want
saved, indexed by key, and uses that path to set the environment to 
that location.

# Setting up a Python virtual environment

This ensures that you are using a specific version of Python.

## Windows

For Python 3.11.x

"C:\Program Files\Python311\python.exe" -m venv venv_py311

venv_py311\Scripts\activate.bat

python --version

conan --version

pip install -r requirements.txt

## macOS

python  -m venv venv_py311

source venv_py311/bin/activate

python --version

conan --version

pip install -r requirements.txt


# How to build

## macOS


```
conan install ./conan/conanfile.txt --build=missing --output-folder=./ --settings build_type=Debug

cmake -G "Xcode" -DCMAKE_BUILD_TYPE=Debug -B ./build -S .
```

## Windows

```
conan install .\conan\conanfile.txt --build=missing --output-folder=.\ --profile=.\conan\windows.txt --settings build_type=Debug

cmake -G "Visual Studio 17 2022" -DCMAKE_BUILD_TYPE=Debug -B .\build -S .
```

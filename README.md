Utility app for having fast folder access.

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
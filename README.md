Utility app for having fast folder access.

# How to build

## Windows
conan install ./conan/conanfile.txt --build=missing --output-folder=./ --profile=./conan/windows.txt --settings build_type=Debug

cmake -G "Visual Studio 17 2022" -DCMAKE_BUILD_TYPE=Debug -B ./build -S .
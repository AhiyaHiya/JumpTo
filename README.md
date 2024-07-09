Utility app for having fast folder access.

# How to build

conan install --build=missing --output-folder=./ --profile=conan/windows.txt --settings build_type=Debug conan/conanfile.txt

cmake -G "Visual Studio 17 2022" --toolchain build/generators/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Debug -B ./build -S .
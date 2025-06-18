Instructions for compiling the project.

For WINDOWS:
1) Before you start, make sure that you have the following components installed:
     - Git - (https://git-scm.com /),
     - CMake - (https://cmake.org /),
     - Visual Studio or MinGW.
     - You can check whether the components are installed using the --version command: cmake --version, gcc --version, cmake --version.
2) Navigate to the folder you need where this project will be located and clone it: git clone https://github.com/hxomak/convertor.git .
3) Move to the cloned folder: cd converter/.
4) Create a build folder and move to it: mkdir build && cd build.
5) Generate the build files using CMake, depending on which compiler you use:
    - if you use Visual Studio: cmake.. -G "Visual Studio <Visual Studio version>", you should insert your IDE version instead of <>;
    - if you have MinGW: cmake.. -G "MinGW Makefiles".
6) Compile the project:
    - with Visual Studio: cmake --build . --config Release;
    - with MinGW: mingw32-make.
7) Run the program: Release/convertor.exe or convertor.exe.

For Linux:
1) Before you start, make sure that you have the following components installed:
    - Git - (https://git-scm.com/),
    - CMake - (https://cmake.org/),
    - GCC or Clang.
    - You can check whether the components are installed using the --version command: git --version, cmake --version, gcc --version.
2) Navigate to the folder you need where this project will be located and clone it: git clone https://github.com/hxomak/convertor.git.
3) Move to the cloned folder: cd convertor/.
4) Create a build folder and move to it: mkdir build && cd build.
5) Generate the build files using CMake: cmake ..
6) Compile the project: make.
7) Run the program: ./convertor.

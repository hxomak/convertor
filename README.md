Инструкция по компиляции проекта.
Для WINDOWS:
1) Перед началом убедитесь, что у вас установлены следующие компоненты:
    Git - (https://git-scm.com/),
    CMake - (https://cmake.org/),
    Visual Studio или MinGW.
    Проверить установлены ли компоненты можно с помощью команды --version: cmake --version, gcc --version, cmake --version.
3) Переместитесь в нужную вам папку, где будет находится этот проект и клонируйте его: git clone https://github.com/hxomak/convertor.git.
4) Переместитесь в клонированную папку: cd convertor/.
5) Создайте папку build и переместитесь в нее: mkdir build && cd build.
6) Сгенерируйте файлы сборки с помощью CMake в зависимости от того, каким компилятором вы пользуетесь:
    - если вы пользуетесь Visual Studio: cmake .. -G "Visual Studio <версия Visual Studio>", вместо <> вы должны вставить версию своего IDE;
    - если у вас MinGW: cmake .. -G "MinGW Makefiles".
7) Скомпилируйте проект:
    - c Visual Studio: cmake --build . --config Release;
    - с MinGW: mingw32-make.
8) Запустите программу: Release/convertor.exe или convertor.exe.

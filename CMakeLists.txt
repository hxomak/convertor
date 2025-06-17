cmake_minimum_required(VERSION 3.31)
project(convertor)

set(CMAKE_CXX_STANDARD 20)

set(INCLUDE include/cnv_constants.h
            include/includes.h
            include/ratio_loader.h
            include/menu_manager.h
            include/currency_converter.h
            include/temperature_converter.h
            include/distance_converter.h
)

set(SOURCE src/ratio_loader.cpp
           src/menu_manager.cpp
           src/currency_converter.cpp
           src/temperature_converter.cpp
           src/distance_converter.cpp
)

add_executable(convertor main.cpp
                         ${INCLUDE}
                         ${SOURCE}
)

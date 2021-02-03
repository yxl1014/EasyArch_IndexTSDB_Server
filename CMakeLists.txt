cmake_minimum_required(VERSION 3.17)
project(Mms)

set(CMAKE_CXX_STANDARD 11)


link_libraries(sqlite3)
add_executable(Mms main.cpp Mms/do.cpp Mms/Mms.h
        Tools/tools.h Tools/tools.cpp main.h
        User/operationUser.cpp User/operationUser.h
        MTools/Mtools.cpp MTools/MTools.h
        )

add_compile_options(-l sqlite3)
target_link_libraries(Mms sqlite3)
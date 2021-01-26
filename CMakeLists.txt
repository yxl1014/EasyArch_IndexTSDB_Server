cmake_minimum_required(VERSION 3.17)
project(Mms)

set(CMAKE_CXX_STANDARD 11)

add_executable(Mms main.cpp Mms/do.cpp Mms/Mms.h
        Tools/tools.h Tools/tools.cpp main.h)
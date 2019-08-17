cmake_minimum_required(VERSION 3.13)
project(cylinderType)

set(CMAKE_CXX_STANDARD 14)

add_executable(pointType.h pointTypeImp.cpp circleType.h circleTypeImp.cpp cylinderType.h
                cylinderTypeImp.cpp cylinderTypeMain.cpp)
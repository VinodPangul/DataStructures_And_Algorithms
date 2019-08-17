cmake_minimum_required(VERSION 3.13)
project(pointType)

set(CMAKE_CXX_STANDARD 14)

#add_executable(pointType pointTypeImp.cpp pointType.h pointTypeMain.cpp)
add_executable(circleType pointTypeImp.cpp pointType.h circleTypeMain.cpp circleType.h circleTypeImp.cpp)


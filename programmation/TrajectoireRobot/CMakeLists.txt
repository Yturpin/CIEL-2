cmake_minimum_required(VERSION 3.5)

project(TrajectoireRobot LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TrajectoireRobot main.cpp
    element.h element.cpp
    segment.h segment.cpp
    trajectoire.h trajectoire.cpp)

include(GNUInstallDirs)
install(TARGETS TrajectoireRobot
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

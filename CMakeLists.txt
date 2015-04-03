cmake_minimum_required (VERSION 3.0)

project (QuantKit)

########################################  Setup Building Settings ######################################################
set(PROJECT_ROOT ${PROJECT_SOURCE_DIR})
set(CMAKE_MODULE_PATH "${PROJECT_ROOT}/cmake")

if(CMAKE_BUILD_TYPE EQUAL "Release")
    set(CMAKE_BUILD_TYPE RelWithDebInfo) # for breakpad
endif()

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()

include(qt)
include(c++11)
include(boost)
include_directories(include 3rd)

#add_subdirectory(3rd)
add_subdirectory(src)
#add_subdirectory(test)

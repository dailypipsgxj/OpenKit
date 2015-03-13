cmake_minimum_required(VERSION 3.0.2)

project(testquantkit)

include_directories(${QuantKit_INCLUDE_DIRS})

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(LIB_SOURCES
    test_Event.cpp
)
#file(GLOB LIB_SOURCES *.cpp)

set(TARGET_LIBRARIES
    Qt5::Core
    Qt5::Test
    ${QuantKit_LIBRARIES}
)

add_executable(${PROJECT_NAME} ${LIB_SOURCES})
target_link_libraries(${PROJECT_NAME} ${TARGET_LIBRARIES})


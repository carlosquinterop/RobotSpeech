project(robotspeech)
cmake_minimum_required(VERSION 3.2.2)

add_definitions(-D UNIX)
add_definitions(-D LINUX)
add_definitions(-D _GNU_SOURCE)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_AUTOMOC NO)
set(CMAKE_INCLUDE_CURRENT_DIR YES)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

set(libs)

# Qt
find_package(Qt5Widgets)
include_directories(${Qt5Widgets_INCLUDES})
list(APPEND libs ${Qt5Widgets_LIBRARIES})

find_package(Qt5Gui)
include_directories(${Qt5Gui_INCLUDES})
list(APPEND libs ${Qt5Gui_LIBRARIES})

find_package(Qt5Core)
include_directories(${Qt5Core_INCLUDES})
list(APPEND libs ${Qt5Core_LIBRARIES})

include_directories(${PROJECT_SOURCE_DIR})

set(SOURCES
    src/main.cpp
    src/RobotSpeech.cpp
)

set(HEADERS     
    include/RobotSpeech.h
)

qt5_wrap_cpp(HEADERS ${HEADERS})

set(srcs
    ${HEADERS}
    ${SOURCES}
)

add_executable(robotspeech ${srcs})
target_link_libraries(robotspeech ${libs})
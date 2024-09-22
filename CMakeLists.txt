cmake_minimum_required(VERSION 3.0)
project(opencv)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE-DIRECTORIES})
add_executable(opencv opencv.cpp)

target_link_libraries(opencv ${OpenCV_LIBS})

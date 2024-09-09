cmake_minimum_required(VERSION 3.0)
project(opencv)

find_package(OpenCV REQUIRED)

# manual specification of the OpenCVConfig.cmake path is necessary since otherwise, cmake assigns /opt/local a higher priority and ocv2.4 will be used
# find_package(OpenCV REQUIRED PATHS /home/27976882/build NO_DEFAULT_PATH)

include_directories(${OpenCV_INCLUDE-DIRECTORIES})
add_executable(opencv opencv.cpp)

target_link_libraries(opencv ${OpenCV_LIBS})

# Google Gemini

# cmake_minimum_required(VERSION 3.0)
# project(webcam)

# find_package(OpenCV REQUIRED)
# include_directories(${OpenCV_INCLUDE-DIRECTORIES})
# add_executable(webcam webcam.cpp)

# target_link_libraries(webcam ${OpenCV_LIBS})

# ChatGPT 4o

# cmake_minimum_required(VERSION 3.0)
# project(webcam4o)

# find_package(OpenCV REQUIRED)
# include_directories(${OpenCV_INCLUDE-DIRECTORIES})
# add_executable(webcam4o webcam4o.cpp)

# target_link_libraries(webcam4o ${OpenCV_LIBS})

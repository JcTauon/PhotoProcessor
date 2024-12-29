cmake_minimum_required(VERSION 3.28)
project(PhotoProcess)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)

add_executable(PhotoProcess main.cpp image_processor.h
        image_processor.cpp)

target_link_libraries(PhotoProcess ${OpenCV_LIBS})


include_directories(${OpenCV_INCLUDE_DIRS})





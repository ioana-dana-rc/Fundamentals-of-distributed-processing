cmake_minimum_required(VERSION 3.29)
project(lab1)

set(CMAKE_CXX_STANDARD 20)

find_package(MPI REQUIRED)
include_directories(${MPI_INCLUDE_PATH})

add_executable(lab1
        blocking_communications.cpp
        non_blocking_communications.cpp
        producer_consumer.cpp
        matrix.cpp)
target_link_libraries(lab1 ${MPI_LIBRARIES})
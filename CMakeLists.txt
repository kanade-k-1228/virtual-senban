cmake_minimum_required(VERSION 3.0.0)
project(virtual-senban)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ADDITIONAL_CFLAGS} -g")
set(CMAKE_CXX_STANDARD 17)

# main
add_executable(main main.cpp)

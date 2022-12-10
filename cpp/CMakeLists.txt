cmake_minimum_required(VERSION 3.9)
project(cpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(LIBRARY_OUTPUT_PATH build/)
set(BINARY_OUTPUT_PATH build/)

set(CMAKE_CXX_FLAGS_DEBUG      "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address,leak,undefined")
set(CMAKE_CXX_LINK_FLAGS_DEBUG "${CMAKE_CXX_LINK_FLAGS_DEBUG} -fsanitize=address,leak,undefined")

include(cmake/External_GTest.cmake)

add_subdirectory(gilded_rose)
add_subdirectory(tests)

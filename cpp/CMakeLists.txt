cmake_minimum_required(VERSION 3.9)
project(cpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(LIBRARY_OUTPUT_PATH build/)
set(BINARY_OUTPUT_PATH build/)

if(NOT MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG      "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address,leak,undefined")
    set(CMAKE_CXX_LINK_FLAGS_DEBUG "${CMAKE_CXX_LINK_FLAGS_DEBUG} -fsanitize=address,leak,undefined")
endif()

add_subdirectory(gilded_rose)

include(CTest)
enable_testing()
include(cmake/External_GTest.cmake)
include(GoogleTest)

add_subdirectory(tests)

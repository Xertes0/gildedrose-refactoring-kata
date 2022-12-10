add_library(gilded_rose)

if(NOT MSVC AND CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(gilded_rose PRIVATE -Wall -Wextra -Wshadow -Wpedantic -Wconversion -Werror)
endif()

target_sources(gilded_rose PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/GildedRose.cc)
target_include_directories(gilded_rose PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(gilded_rose)

target_sources(gilded_rose PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/GildedRose.cc)
target_include_directories(gilded_rose PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
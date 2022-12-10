add_executable(GildedRoseUnitTests)
target_sources(
    GildedRoseUnitTests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/GildedRoseUnitTests.cc
)
target_link_libraries(
    GildedRoseUnitTests
    PRIVATE
    gilded_rose
    ${GTEST_MAIN_LIBRARY}
    ${GTEST_LIBRARY}
)

gtest_discover_tests(GildedRoseUnitTests)
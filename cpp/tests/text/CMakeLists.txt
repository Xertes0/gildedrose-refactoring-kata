add_executable(GildedRoseTextTests)
target_sources(
    GildedRoseTextTests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/GildedRoseTextTests.cc
)
target_link_libraries(
    GildedRoseTextTests
    PRIVATE
    gilded_rose
    ${GMOCK_MAIN_LIBRARY}
    ${GMOCK_LIBRARY}
)

gtest_discover_tests(GildedRoseTextTests)

cmake_minimum_required(VERSION 3.5)

project("game-of-life")
set(CMAKE_CXX_STANDARD 11)

find_package(SDL REQUIRED)

include_directories(${SDL_INCLUDE_DIRS} "include")

set(SRC_FILE
"src/Model.cpp"
)

set(TEST_FILE
"test/HelloTest.cpp"
"test/TestgetNeighbor.cpp"
)
INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL REQUIRED sdl)
INCLUDE_DIRECTORIES(${SDL_INCLUDE_DIRS})

add_executable(game_of_life ${SRC_FILE} "src/main.cpp")
TARGET_LINK_LIBRARIES(game_of_life ${SDL_LIBRARIES})

add_executable(gol_test ${SRC_FILE} ${TEST_FILE} "test/TestRunner.cpp")

enable_testing()
add_test(NAME "game_of_life_test" COMMAND "gol_test")
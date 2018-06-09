cmake_minimum_required(VERSION 3.5)

project("game-of-life")
set(CMAKE_CXX_STANDARD 11)

include_directories("include")

set(SRC_FILE
"src/Model.cpp"
)

set(TEST_FILE
"test/HelloTest.cpp"
)

add_executable(game_of_life ${SRC_FILE} "src/main.cpp")

add_executable(gol_test ${SRC_FILE} ${TEST_FILE} "test/TestRunner.cpp")

enable_testing()
add_test(NAME "game_of_life_test" COMMAND "gol_test")
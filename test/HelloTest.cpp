
#include <catch.hpp>

#include "Model.hpp"

// See https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md
//     https://github.com/catchorg/Catch2/blob/master/docs/command-line.md

TEST_CASE("should return 'hello world' when call method hello()", "[hello_test]") {
    const char* message = "hello world";
    REQUIRE(message == "hello world");
}

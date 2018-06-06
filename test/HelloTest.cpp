
#include <catch.hpp>

#include "hello.hpp"

// See https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md
//     https://github.com/catchorg/Catch2/blob/master/docs/command-line.md

TEST_CASE("should return 'hello world' when call method hello()", "[hello_test]") {
    auto message = hello();
    REQUIRE(message == "hello world");
}

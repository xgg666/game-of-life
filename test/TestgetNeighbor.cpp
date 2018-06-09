
#include <catch.hpp>

#include "Model.hpp"

// See https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md
//     https://github.com/catchorg/Catch2/blob/master/docs/command-line.md

bool test_someCellAfterOne(string s, int n, int m, string outAnswer) {
	Model *test_Model = new Model(n, m);
	test_Model -> writeModel(s);
	//test_Model -> priModel();
	test_Model -> getNeighborNumber();
	return outAnswer == test_Model -> getAllCellsNeighbor();
}

TEST_CASE("should return answer when call method getAllCellsNeighbor1()", "[TestgetNeighbor1]") {
    REQUIRE(test_someCellAfterOne("111111111", 3, 3, "353585353"));
}

TEST_CASE("should return answer when call method getAllCellsNeighbor2()", "[TestgetNeighbor2]") {
    REQUIRE(test_someCellAfterOne("101010010", 3, 3, "131333212"));
}

TEST_CASE("should return answer when call method getAllCellsNeighbor3()", "[TestgetNeighbor3]") {
    REQUIRE(test_someCellAfterOne("101111101", 3, 3, "252363252"));
}

#include <catch.hpp>

#include "Model.hpp"

// See https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md
//     https://github.com/catchorg/Catch2/blob/master/docs/command-line.md

bool test_someCellAfterOne(string s, int n, int m, string outAnswer) {
	Model *test_Model = new Model(n, m);
	test_Model -> writeModel(s);
	//test_Model -> printModel();
	test_Model -> getNeighborLiveNumber();
	//cout<< test_Model->getAllCellsNeighbor()<<endl;
	return outAnswer == test_Model -> getAllCellsNeighborNumber();
}

bool test_changeCellsStatus(string s, int n, int m, string outAnswer) {
	Model *test_Model = new Model(n, m);
	test_Model -> writeModel(s);
	//test_Model -> printModel();
	test_Model -> getNeighborLiveNumber();
	//cout << test_Model->changeCellsStatus()<<endl;
	return outAnswer == test_Model -> changeCellsStatus();
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


TEST_CASE("should return next status when call method changeCellsStatus1()", "[TestchangeCellsStatus1]") {
	REQUIRE(test_changeCellsStatus("101111101", 3, 3, "101101101"));
}

TEST_CASE("should return next status when call method changeCellsStatus2()", "[TestchangeCellsStatus2]") {
	REQUIRE(test_changeCellsStatus("101010010", 3, 3, "010111000"));
}

TEST_CASE("should return next status when call method changeCellsStatus3()", "[TestchangeCellsStatus3]") {
	REQUIRE(test_changeCellsStatus("111111111", 3, 3, "101000101"));
}

TEST_CASE("should return next status when call method changeCellsStatus4()", "[TestchangeCellsStatus4]") {
	REQUIRE(test_changeCellsStatus("1111", 2, 2, "1111"));
}

TEST_CASE("should return next status when call method changeCellsStatus5()", "[TestchangeCellsStatus5]") {
	REQUIRE(test_changeCellsStatus("111", 1, 3, "010"));
}

TEST_CASE("should return next status when call method changeCellsStatus6()", "[TestchangeCellsStatus6]") {
	REQUIRE(test_changeCellsStatus("111", 3, 1, "010"));
}
#include"Model.hpp"

/*
  测试矩阵初始化
*/
void test_initModel(int n, int m) {
    Model *test_Model = new Model(n, m);
    test_Model -> initModel();
    test_Model -> priModel();
}

void test_someCellAfterOne(string s, int n, int m) {
	Model *test_Model = new Model(n, m);
	test_Model -> writeModel(s);
	//test_Model -> priModel();
	test_Model -> getNeighborNumber();
	//test_Model -> getAllCellsNeighbor();
}

int main() {
   
   // test_initModel(50, 50);

    test_someCellAfterOne("111111111", 3, 3);
    test_someCellAfterOne("101010010", 3, 3);
}

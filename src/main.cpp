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

void ShowModelMatrix(int n, int m) {
	system("reset");
	Model *showModel = new Model(n, m);
	//showModel -> writeModel(s);
	showModel -> initModel();
	for (int tim = 1; tim <= 100; tim++) {
		showModel -> priModel();
		showModel -> changeCellsStatus();
		cout << endl;
		sleep(1);
		system("reset");
	}
}

int main() {
   
   // test_initModel(50, 50);

    //test_someCellAfterOne("111111111", 3, 3);
   // test_someCellAfterOne("101010010", 3, 3);
		ShowModelMatrix(50, 50);
}

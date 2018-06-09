#include"Model.hpp"

/*
  测试矩阵初始化
*/
void test_initModel(int n, int m) {
    Model *test_Model = new Model(n, m);
    test_Model -> initModel();
    test_Model -> priModel();
}

int main() {
    //测试地图初始化
    //初始定义一个50×50的矩阵
    test_initModel(50, 50);
}

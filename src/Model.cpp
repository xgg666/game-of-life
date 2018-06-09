#include"Model.hpp"

/*
  initModel()用于初始化矩阵内细胞的存活状态
*/
void Model::initModel() {

    //设置随机种子，用于随机生成活细胞
    srand(time(0));


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            /*
            用于决定细胞的生死，
            1--代表细胞为活细胞
            0--代表细胞为死细胞
            */
            int flag = rand()&1;

            Matrix[i][j] = flag;
        }
    }

}

/*
  初始化矩阵的大小n*m
*/
Model::Model(int tn, int tm) {
    n = tn, m = tm;
}

/*
  输出矩阵内的细胞的存活状态
*/

void Model::priModel() {
    using namespace std;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (Matrix[i][j] == 1) {
                cout << AliveCell;
            }
            else cout << DeadCell;
        }
        cout << endl;
    }
}

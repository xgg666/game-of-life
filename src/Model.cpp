#include"Model.hpp"

/*
  initModel()用于初始化矩阵内细胞的存活状态
*/

Model::Model() {

}
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

bool Model::locationSafe(int x, int y) {

    if (x>0&&x<=n&&y>0&&y<=m)  return true;

    return false;

}

/*
  获取一个细胞的八个方向一共有多少个活细胞
*/
void Model::getNeighborNumber() {

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int liveCell=0;
            for (int k = 0; k < 8; k++) {


                int nextX = i+dir[k][0];
                int nextY = j+dir[k][1];

                if (locationSafe(nextX, nextY) && Matrix[nextX][nextY]==true) {
                    liveCell++;
                }
            }
            liveNeighbor[i][j] = liveCell;

        }
    }

}

int Model::getMyNeighbor(int x, int y) {

    return liveNeighbor[x][y];

}

string Model::getAllCellsNeighbor() {
    string outNeighbor;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
           // cout<<liveNeighbor[i][j]<<" ";
            outNeighbor += liveNeighbor[i][j] + '0';
        }
//        cout << endl;
    }
    return outNeighbor;
}

void Model::writeModel(string s) {

    for (int i = 1; i <= n; i++) {
        for (int j=1; j<= m; j++) {
            Matrix[i][j] = s[(i-1)*n+j-1]-'0';
        }
    }

}


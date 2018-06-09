#include"Model.hpp"

/*
  initModel()用于初始化矩阵内细胞的存活状态
*/

Model::Model() {

}
void Model::initModel() {

    //设置随机种子，用于随机生成活细胞
    srand(time(0));


    for (int row = 1; row <= n; row++) {
        vector<bool> rowCellStatus;
        rowCellStatus.push_back(0);
        for (int col = 1; col <= m; col++) {

            /*
            用于决定细胞的生死，
            1--代表细胞为活细胞
            0--代表细胞为死细胞
            */
            bool cellStatus = rand()&1;
            rowCellStatus.push_back(cellStatus);
           // Matrix[row][col] = cellStatus;
        }
        Matrix.push_back(rowCellStatus);
    }

}

/*
  初始化矩阵的大小n*m
*/
Model::Model(int tn, int tm) {
    vector<bool> notUse;    //
    Matrix.push_back(notUse);
    n = tn, m = tm;
}

/*
  输出矩阵内的细胞的存活状态
*/

void Model::printModel() {
    using namespace std;

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= m; col++) {
            if (Matrix[row][col] == 1) {
                cout << AliveCell;
            }
            else cout << DeadCell;
        }
        cout << endl;
    }
}

bool Model::locationSafeOrDead(int row, int col) {

    if (row>0 && row<=n && col>0 && col<=m)  return true;

    return false;

}

/*
  获取一个细胞的八个方向一共有多少个活细胞
*/
void Model::getNeighborLiveNumber() {

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= m; col++) {
            int liveCell=0;
            for (int k = 0; k < 8; k++) {


                int nextX = row+dir[k][0];
                int nextY = col+dir[k][1];

                if (locationSafeOrDead(nextX, nextY) && Matrix[nextX][nextY]==true) {
                    liveCell++;
                }
            }
            liveNeighbor[row][col] = liveCell;

        }
    }

}

int Model::getMyNeighbor(int row, int col) {

    return liveNeighbor[row][col];

}

string Model::getAllCellsNeighborNumber() {
    string outNeighbor;
    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= m; col++) {
           // cout<<liveNeighbor[i][j]<<" ";
            outNeighbor += liveNeighbor[row][col] + '0';
        }
//        cout << endl;
    }
    return outNeighbor;
}



void Model::writeModel(string s) {

    for (int row = 1; row <= n; row++) {
        vector<bool> rowCellStatus;
        rowCellStatus.push_back(0);
        for (int col = 1; col <= m; col++) {
            rowCellStatus.push_back(s[(row-1)*n+col-1]-'0');
        }
        Matrix.push_back(rowCellStatus);
    }

}

bool Model::getCellNextStatus(int currentStatus, int currentLiveNeighbrNumber) {
    if (currentLiveNeighbrNumber < 2)  return false;
    if (currentLiveNeighbrNumber > 3)  return false;
    if (currentLiveNeighbrNumber == 3)  return true;
    if (currentLiveNeighbrNumber == 2)  return currentStatus;
}


string Model::changeCellsStatus() {
    string outNextStatus;
    getNeighborLiveNumber();
    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= m; col++) {
            
            Matrix[row][col] = getCellNextStatus(Matrix[row][col], liveNeighbor[row][col]);
            outNextStatus += (int)Matrix[row][col] + '0';
        }
    }
    return outNextStatus;

}
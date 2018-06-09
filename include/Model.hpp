#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <vector>

#define size_x 1000
#define size_y 1000
#define AliveCell '*'
#define DeadCell ' '
using namespace std;

const int dir[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

class Model {
private:
    //矩阵
    //bool Matrix[size_x][size_y];
    vector<vector<bool> >Matrix;
    //矩阵大小为n*m
    int n, m;
    //int liveNeighbor[size_x][size_y];
    vector<vector<int> > liveNeighbor;
    bool getCellNextStatus(int currentStatus, int currentLiveNeighbrNumber);
public:
    Model();
    Model(int tn, int tm);
    //用于初始化矩阵内细胞的存活状态
    void initModel();
    //初始化矩阵的大小n*m
    void printModel();
    //获取一个细胞的八个方向一共有多少个活细胞
    void getNeighborLiveNumber();
    vector<vector<bool> > getModel();
    bool locationSafeOrDead(int x, int y);

    int getMyNeighbor(int x, int y);


    void writeModel(string s);

    string getAllCellsNeighborNumber();

    string changeCellsStatus();

    ~Model();
};


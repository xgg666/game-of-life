#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>

#define size_x 1000
#define size_y 1000
#define AliveCell '*'
#define DeadCell ' '

class Model {
private:
    //矩阵
    bool Matrix[size_x][size_y];
    //矩阵大小为n*m
    int n, m;
public:
    Model(int tn, int tm);
    //用于初始化矩阵内细胞的存活状态
    void initModel();
    //初始化矩阵的大小n*m
    void priModel();
    ~Model();
};

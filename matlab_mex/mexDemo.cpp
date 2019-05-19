#include "mex.h"
#include <vector>
#include "Eigen/Eigen/Dense"
#include <iostream>
using namespace std;
 
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]){
    int x = mxGetScalar(prhs[0]); //将第一个输入参数转为Scalar标量，也就是单数值
    printf("%d\n", x); //打印
   
    vector< int > ivec( 10 );     

    Eigen::MatrixXd m(2,2);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);
    std::cout << "Here is the matrix m:\n" << m << std::endl;
    double *y;
    plhs[0] = mxCreateDoubleMatrix(1,1,mxREAL); //让第一个输出参数指向一个1*1的矩阵
    y = mxGetPr(plhs[0]); //获得矩阵的第一个元素的指针
    *y = 10; //将其赋值为10
}
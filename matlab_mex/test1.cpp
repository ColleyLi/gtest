#include "mex.h"
#include <vector>
#include "Eigen/Eigen/Dense"
#include <iostream>
#include <string.h> /**< memcpy */
using namespace std;

void timestwo_alt(double *y, double x)
{
*y = 2.0*x;
}
 
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]){
//     int x = mxGetScalar(prhs[0]); //将第一个输入参数转为Scalar标量，也就是单数值
//     printf("%d\n", x); //打印
//    
//     vector< int > ivec( 10 );     
// 
//     Eigen::MatrixXd m(2,2);
//     m(0,0) = 3;
//     m(1,0) = 2.5;
//     m(0,1) = -1;
//     m(1,1) = m(1,0) + m(0,1);
//     std::cout << "Here is the matrix m:\n" << m << std::endl;
//     double *y;
//     plhs[0] = mxCreateDoubleMatrix(1,1,mxREAL); //让第一个输出参数指向一个1*1的矩阵
//     y = mxGetPr(plhs[0]); //获得矩阵的第一个元素的指针
//     *y = 10; //将其赋值为10
    
    
    
double *M;
int m,n; //指针指向第一个参数的数据地址
M = mxGetPr(prhs[0]);
m = mxGetM(prhs[0]);
n = mxGetN(prhs[0]);
printf("m: %d,n: %d",m,n);
plhs[0] = mxCreateDoubleMatrix(m,n, mxREAL); //生成m x n 的实矩阵，分配内存空间 
double *A;
A = mxGetPr(plhs[0]); 
printf("M: %d",*M);
int index = 0;
// memcpy(mxGetPr(A), M, sizeof(double)*m*n);
memcpy(A, M, sizeof(double)*m*n);

// timestwo_alt(A,*M); //调用并直接赋值到指针指向的输出变量
}
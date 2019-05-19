# DSP

1、必须添加 #include “mex.h” 
2、四个参数分别用来输出和输入数据: nlhs（number left hand side） 是输出参数个数，plhs 是输出参数指针；nrhs (number right hand side)是输入参数个数，prhs 是输入参数指针。（想象成一个赋值等式：a = b+c）b和c是需要输入的自变量位于右边 注意: 对输出和输入参数的操作都是通过指针的方式进行的。
3、操作输入数据对输入数据进行操作，需要通过MEX函数mxGetPr 得到数据的指针地址。 mxGetM 和 mxGetN 得到矩阵数据的行和列 (返回整数)。
4、plhs[0] = mxCreateDoubleMatrix(m,n, mxREAL); //生成m x n 的实矩阵，分配内存空间。
5、A = mxGetPr(plhs[0]); 输出矩阵 #include <string.h> /**< memcpy */  memcpy(A, M, sizeof(double)*m*n);

####Demo:
```c
#include "mex.h"
#include <vector>
#include "Eigen/Eigen/Dense"
#include <iostream>
#include <string.h> /**< memcpy */
using namespace std;

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]){
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
    memcpy(A, M, sizeof(double)*m*n);
}


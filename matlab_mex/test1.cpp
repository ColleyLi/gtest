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
//     int x = mxGetScalar(prhs[0]); //����һ���������תΪScalar������Ҳ���ǵ���ֵ
//     printf("%d\n", x); //��ӡ
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
//     plhs[0] = mxCreateDoubleMatrix(1,1,mxREAL); //�õ�һ���������ָ��һ��1*1�ľ���
//     y = mxGetPr(plhs[0]); //��þ���ĵ�һ��Ԫ�ص�ָ��
//     *y = 10; //���丳ֵΪ10
    
    
    
double *M;
int m,n; //ָ��ָ���һ�����������ݵ�ַ
M = mxGetPr(prhs[0]);
m = mxGetM(prhs[0]);
n = mxGetN(prhs[0]);
printf("m: %d,n: %d",m,n);
plhs[0] = mxCreateDoubleMatrix(m,n, mxREAL); //����m x n ��ʵ���󣬷����ڴ�ռ� 
double *A;
A = mxGetPr(plhs[0]); 
printf("M: %d",*M);
int index = 0;
// memcpy(mxGetPr(A), M, sizeof(double)*m*n);
memcpy(A, M, sizeof(double)*m*n);

// timestwo_alt(A,*M); //���ò�ֱ�Ӹ�ֵ��ָ��ָ����������
}
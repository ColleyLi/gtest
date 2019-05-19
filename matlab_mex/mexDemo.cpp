#include "mex.h"
#include <vector>
#include "Eigen/Eigen/Dense"
#include <iostream>
using namespace std;
 
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]){
    int x = mxGetScalar(prhs[0]); //����һ���������תΪScalar������Ҳ���ǵ���ֵ
    printf("%d\n", x); //��ӡ
   
    vector< int > ivec( 10 );     

    Eigen::MatrixXd m(2,2);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);
    std::cout << "Here is the matrix m:\n" << m << std::endl;
    double *y;
    plhs[0] = mxCreateDoubleMatrix(1,1,mxREAL); //�õ�һ���������ָ��һ��1*1�ľ���
    y = mxGetPr(plhs[0]); //��þ���ĵ�һ��Ԫ�ص�ָ��
    *y = 10; //���丳ֵΪ10
}
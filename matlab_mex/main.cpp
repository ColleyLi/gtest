#include <iostream>
#include "linear_quadratic_regulator.cpp"
#include "mex.h"
#include <vector>
#include "Eigen/Eigen/Dense"


// using Matrix = Eigen::MatrixXd;
// 
// void SolveLQRProblem(const Matrix &A, const Matrix &B, const Matrix &Q,
//                      const Matrix &R, const double tolerance,
//                      const int max_num_iteration, Matrix *ptr_K) {
//   if (A.rows() != A.cols() || B.rows() != A.rows() || Q.rows() != Q.cols() ||
//       Q.rows() != A.rows() || R.rows() != R.cols() || R.rows() != B.cols()) {
//     std::cout << "LQR solver: one or more matrices have incompatible dimensions.";
//     return;
//   }
// 
//   Matrix AT = A.transpose();
//   Matrix BT = B.transpose();
// 
//   // Solves a discrete-time Algebraic Riccati equation (DARE)
//   // Calculate Matrix Difference Riccati Equation, initialize P and Q
//   Matrix P = Q;
//   int num_iteration = 0;
//   double diff = 1000;
//   while (num_iteration++ < max_num_iteration && diff > tolerance) {
//     Matrix P_next =
//         AT * P * A - AT * P * B * (R + BT * P * B).inverse() * BT * P * A + Q;
//     // check the difference between P and P_next
//     diff = fabs((P_next - P).maxCoeff());
//     P = P_next;
//   }
// 
//   if (num_iteration >= max_num_iteration) {
//     std::cout << "LQR solver cannot converge to a solution, "
//               "last consecutive result diff is: "
//            << diff;
//   } else {
//     std::cout  << "LQR solver converged at iteration: " << num_iteration
//            << ", max consecutive result diff.: " << diff;
//   }
//   *ptr_K = (R + BT * P * B).inverse() * BT * P * A;
// }

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]){

    Eigen::MatrixXd matrix_a_(4,4) ;
    matrix_a_ = Eigen::MatrixXd::Zero(4, 4);
    Eigen::MatrixXd matrix_b_(4,1); 
    matrix_b_= Eigen::MatrixXd::Zero(4, 1);
    Eigen::MatrixXd matrix_r_(4,4);
    matrix_r_= Eigen::MatrixXd::Zero(4, 4);
    Eigen::MatrixXd matrix_q_(1,1);
    matrix_q_= Eigen::MatrixXd::Zero(1,1);
    
    matrix_a_ << 0   ,  1 ,    0  ,   0  ,
                          0   ,  0  ,  -1 ,    0 ,
                          0   ,  0   ,  0   ,  1 ,
                          0  ,   0  ,   9  ,   0;
    
    matrix_b_ <<          0   ,
                               0.1000 ,
                                    0  ,
                                -0.1000;
    
    matrix_r_ <<        1     ,0     ,0     ,0 ,
                                0     ,1     ,0     ,0,
                                0     ,0    ,10   , 0,
                                0     ,0     ,0   , 10;
    std::cout << matrix_a_ << std::endl;
    
     Eigen::MatrixXd matrix_k_;
     matrix_k_ = Eigen::MatrixXd::Zero(1, 4);
    double tolerance = 0.01;
    int maxIter = 100;
    SolveLQRProblem(matrix_a_,matrix_b_,matrix_r_,matrix_q_,tolerance,maxIter,&matrix_k_);
    std::cout << "matrix_k_: " << matrix_k_ <<  std::endl;

}

#ifndef CGSOLVER_INCLUDED
#define CGSOLVER_INCLUDED

#include<iostream>
#include<vector>

int CGSolver(std::vector<double> &val,
             std::vector<int> &row_count,
             std::vector<int> &col_idx,
             std::vector<double> &b,
             std::vector<double> &x,
             double   tol);

#endif /*CGSolver.h*/

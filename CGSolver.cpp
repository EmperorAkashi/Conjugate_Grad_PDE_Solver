#include<iostream>
#include<vector>
#include<cmath>
#include "matvecops.h"
#include "CGSolver.h"

int CGSolver(std::vector<double> &val, 
	     std::vector<int> &row_count, 
	     std::vector<int> &col_idx,
             std::vector<double> &b,
	     std::vector<double> &u,
	     double      tol)
{
 int steps = 2*u.size();
 if (!same_size(u,b))
    return 0;
 
 std::vector<double> r = b;
 std::vector<double> A_x = matdotvec(val, col_idx, row_count, u);
 r = sum(r, A_x, -1);
 double norm;
 norm = L2norm(r);
 std::vector<double> p = r;
 
 int t = 0;
 while (t < steps)
 {
  t += 1;
  double rr = pow(L2norm(r),2);
  double alpha;
  //update alpha
  std::vector<double> A_p = matdotvec(val, col_idx, row_count, p);
  double pA_p = dot_prod(p, A_p);
  alpha = rr/pA_p;
  u = sum(u, p, alpha);
  r = sum(r, A_p, -1*alpha);
  int L2_r = L2norm(r);
  if (L2_r/norm < tol)
    break;
  double beta = pow(L2_r,2)/rr;
  scalar_prod(p, beta);
  p = sum(p, r, 1.0); 
 }
 if (t < steps)
    return steps;
 else 
    return -1;
}



#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include "CGSolver.h"
#include "COO2CSR.h"
#include "matvecops.h"
using namespace std;

int main(int argc, char* argv[])
{
 // argc = argument count, argv = argument value
 if(argc < 3)
 {
  cout << "Usage:" << endl;
  cout << " " << argv[0] << " <input><output>" << endl;
   
 return 0;
 }
 //initialize COO format matrix from argv[1]
 std::string mat_name = argv[1];
 std::string sol_name = argv[2];

 //initialize vectors to store coverted array from COO to CSR 
 std::vector<double> val;
 std::vector<int> row_idx, col_idx;
 //total number of row&col of sqr mat, specified in the first line of COO
 int nrows, ncols;
 std::ifstream maho;
 maho.open(mat_name.c_str());
 if (maho.is_open())
 {
  maho >> nrows >> ncols;
  int r_i, c_i;
  double v_i;
  while (maho >> r_i >> c_i >> v_i)
  {
   //append each row, column index and value into a list
   //by def, col_idx & val automatically in CSR format
   row_idx.push_back(r_i);
   col_idx.push_back(c_i);
   val.push_back(v_i);
  }
  maho.close();
 }
 else
   cout << "cannot red the input matrix" << endl; 
 
 std::vector<int> row_count = transfer(row_idx); //convert row_idx into CSR format
 
 std::vector<double> b(ncols, 0.0), u(ncols, 1.0);
 double tol = 1.0e-5;

 int niter = CGSolver(val, row_count, col_idx, b, u, tol);
 
 if (niter == -1)
   cout << "solution does not converged" << endl; 
 std::ofstream solf;
 solf.open(sol_name.c_str());
 if(solf.is_open())
 {
  for (double sols: u)
    solf << sols << endl;
  solf.close();
 }
 cout << "SUCCESS: CGSOlver converged in" << "niter" << "iteration" << endl;
}


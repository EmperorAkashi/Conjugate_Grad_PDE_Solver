#include "matvecops.h"
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

bool same_size(std::vector<double> &a, std::vector<double> &b)
{
 if(a.size() != b.size())
 {
  cout << "ERROR: two vectors have different size" << endl;
  return false;
 }
 return true;
}

std::vector<double> sum(std::vector<double> &a, std::vector<double> &b, double c)
{
  std::vector<double> wrong;
 if(!same_size(a,b))
  {  
      cout << "two vectors have different size" << endl;
   return wrong;
  }
 for(int i = 0; i < a.size(); i++)
 {
  a[i] += c*b[i];
 }
 return a; 
}

void scalar_prod(std::vector<double> &a, double c)
{
 for(int i = 0; i < a.size(); i++)
 {
  a[i] *= c;
 }
}

double dot_prod(std::vector<double> &a, std::vector<double> &b)
{
 if(!same_size(a,b))
  return 0.0;
 double piece_sum;
 for (int i = 0; i < a.size(); i++)
 {
  piece_sum += a[i]*b[i];
 }
 return piece_sum;
}

double L2norm(std::vector<double> &a)
{
 return std::sqrt(dot_prod(a,a));
}

std::vector<double> matdotvec(std::vector<double> &val,
                              std::vector<int> &col_idx,
                              std::vector<int> &row_count,
                              std::vector<double> &x)
{
 std::vector<double> b;
 
 int max_r = row_count.size();
 if (max_r != x.size())
 {
  cout << "ERROR: matrix and vector size not match" << endl;
  return b;
 }
 for(int i = 0; i < row_count.size()-1; i++)
 {
  double entry = 0;
  for (int j = row_count[i]; j < row_count[i+1]; j++)
  {
   entry += val[j]*x[col_idx[j]];
  }
  b.push_back(entry);
 }
 return b;
}

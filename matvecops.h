#ifndef MATVECOPS_INCLUDED
#define MATVECOPS_INCLUDED

#include <vector>

bool same_size (std::vector<double> &a, std::vector<double> &b);

std::vector<double> sum(std::vector<double> &a, std::vector<double> &b, double c);

void scalar_prod(std::vector<double> &a, double c);

double dot_prod(std::vector<double> &a, std::vector<double> &b);

double L2norm(std::vector<double> &a);

std::vector<double> matdotvec(std::vector<double> &val,
                              std::vector<int> &col_idx,
                              std::vector<int> &row_count,
                              std::vector<double> &x);

#endif /*MATVECOPS*/

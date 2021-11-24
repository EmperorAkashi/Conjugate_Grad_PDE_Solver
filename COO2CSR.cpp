#include "COO2CSR.h"
#include<iostream>
#include<vector>
using namespace std;

std::vector<int> transfer(std::vector<int> &coo_row)
{
 vector<int>    r_idx;
 int flag = 0;
 int count = 0;
 r_idx.push_back(0);
 for(int i = 1; i < coo_row.size(); i++)
 {
  if (coo_row[i] == flag)
   count += 1;
  else
  {
    r_idx.push_back(count);
    flag += 1;
    count = 0;
  }
  
  }
  return r_idx; 
 }


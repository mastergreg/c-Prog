#include <iostream>   
#include <cstdlib>   
#include <cstdio>   
#include <fstream>
#include <algorithm>
#include <cstring>   
#include "lcs_hirschberg.h"

using namespace std;   

int main()   
{   
  string str1,str2;   


  ifstream myfile("softlab.txt");
  getline (myfile,str1);
  str2=str1;
  reverse(str2.begin(),str2.end());
  return 0;   
}   

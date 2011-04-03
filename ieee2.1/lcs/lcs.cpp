#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string.h>
#include <algorithm>
#include "lcslib.h"
using namespace std;

int main()
{
  size_t maxi;
  string anotherstring="",line,fileline;
  ifstream myfile("softlab.txt");
  getline (myfile,fileline);
  maxi=fileline.length();
  line=fileline;
  reverse(line.begin(),line.end());
//  cout << line<<endl;
//  cout << fileline<<endl;

  cout << lcs(line.c_str(),fileline.c_str())<<endl;
  
}


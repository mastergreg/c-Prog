#include "palindrome.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
int find_pal(unsigned int lim,string mystr);



int main()
{
  unsigned int limit=500000;
  string line;
  ifstream myfile("softlab.txt");
  getline (myfile,line);
  while (line.size()>limit)
  {
    limit = max((int)limit,find_pal(limit,line)); 
    cout << limit <<endl;
    line.erase(line.begin());
  }
  
}

int find_pal(unsigned int lim,string mystr)
{
  unsigned int a=mystr.size();
  while (a>=lim)
  {
    if (ispalindrome(mystr.c_str()))
    {
      return a;
    }
    else
    {
      mystr.erase(mystr.end()-1);
    }
    a=mystr.size();
  }
  return 0;
}



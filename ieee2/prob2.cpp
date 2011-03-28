#include "palindrome.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
int locate_pals(string mystr);
int find_pal(unsigned int lim,string mystr);



int main()
{
  int maxi,limiteven=2,limitodd=3;
  int i;
  string line,testline;
  ifstream myfile("endo.dna");
  getline (myfile,line);
  maxi=line.size();
  cout << "line size is " << maxi << endl;
  for(i=0;i<(maxi-limiteven);i++)
  {
    testline=line.substr(i,limiteven);
    if (ispalindrome(testline.c_str()))
    {
      limiteven+=2;
      i=i>2?i-2:i;
    }
  }
  for(i=0;i<maxi-limitodd;i++)
  {
    testline=line.substr(i,limitodd);
    if (ispalindrome(testline.c_str()))
    {
      limitodd+=2;
      i=i>2?i-2:i;
    }
  }
  cout << "the limit is " << max(limiteven,limitodd)-2 << endl;
  //  testline=line.substr(0,line.size()/8);
  //  limit=locate_pals(testline);
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



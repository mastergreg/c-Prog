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
  unsigned int limit=7074;
  int i,maxi;
  string line,testline;
  ifstream myfile("endo.dna");
  getline (myfile,line);
  maxi=line.size()/768;
  for(i=0;i<768;i++)
  {
    testline=line.substr(i*maxi,maxi);
    while (testline.size()>limit)
    {
      limit = max((int)limit,find_pal(limit,testline)); 
      testline.erase(testline.begin());
    }

    cout << "i= "<<i<<endl;
  }
  //  for(i=0;i<768;i++)
  //
  //  {
  //    testline=line.substr(i*maxi+maxi/2,maxi);
  //    while (testline.size()>limit)
  //    {
  //      limit = max((int)limit,find_pal(limit,testline)); 
  //      testline.erase(testline.begin());
  //    }
  //
  //    cout << "i= "<<i<<endl;
  //  }
  cout << "the limit is " << limit << endl;
  //  testline=line.substr(0,line.size()/8);
  //  limit=locate_pals(testline);
}


int find_pal(unsigned int lim,string mystr)
{
  unsigned int a=mystr.size();
  ofstream outfile("thestring");
  while (a>=lim)
  {
    if (ispalindrome(mystr.c_str()))
    {
      cout << mystr.c_str() << endl;
      outfile << mystr.c_str() << endl << endl;
      return a;
    }
    else
    {
      mystr.erase(mystr.end()-1);
      a=mystr.size();
    }
  }
  return 0;
}



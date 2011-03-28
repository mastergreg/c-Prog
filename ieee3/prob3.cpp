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
  int limit=7075;
  int i,maxi;
  string line,testline;
  ifstream myfile("endo.dna");
  ofstream outfile("thestring");
  getline (myfile,line);
  maxi=line.size()-limit;
  cout << maxi<<endl;
  for(i=0;i<=maxi;i++)
  {
    testline=line.substr(i,7075);
    if(ispalindrome(testline.c_str()))
    { 
      outfile  << testline;
      return 0;
    }
  }
  cout << testline.size() << endl;
  cout << "the limit is " << limit << endl;
}

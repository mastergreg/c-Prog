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
  //  unsigned int limit=500000;
  string line;
  ifstream myfile("softlab.txt");
  getline (myfile,line);
  //  while (line.size()>limit)
  //  {
  //    limit = max((int)limit,find_pal(limit,line)); 
  //    cout << limit <<endl;
  //    line.erase(line.begin());
  //  }
  locate_pals(line);
}

int locate_pals(string mystr)
{
  string buf = mystr;
  size_t found;
  while (mystr.size()>1)
  {
    cout << buf.size() << endl;
    while(buf.size()>1)
    { 
      found=buf.rfind(buf[0]);
      buf=buf.substr(0,found);
      if (ispalindrome(buf.c_str()))
      {
        cout << buf << endl;
      }
    }
    mystr.erase(mystr.begin());
    buf=mystr;
  }
  return 0;
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



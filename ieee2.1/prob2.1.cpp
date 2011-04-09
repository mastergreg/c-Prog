#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;
unsigned int lcs_len(char *,char *);
unsigned int recursion_level=0;
char *xinit,*ystop;
int main()
{
  unsigned int maxi;
  string line;
  ifstream myfile("softlab.txt");
  getline (myfile,line);
  maxi=line.size();
  char *xinit=new (nothrow) char[maxi];
  strncpy(xinit,line.c_str(),maxi);
  ystop=xinit+(maxi)*sizeof(char);
  cout << lcs_len(ystop,xinit) <<endl;
  return 0;
}


unsigned int lcs_len(char *xi,char *yi)
{
  unsigned int counter = 0,a,b;
  cout << ++recursion_level << endl;
  while (xi>xinit && yi<ystop)
  {
    if (*xi==*yi)
    {
      counter++;
      xi--;
      yi++;
    }
    else
    {
      a=lcs_len(--xi,yi);
      b=lcs_len(xi,--yi);
      counter += (b<a)?a:b;
    }
  }
  return counter;
}

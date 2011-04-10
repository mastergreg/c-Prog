#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;
unsigned int lcs_len(char *,char *);
unsigned int lcs_len_slow(char *chi,char *chj,unsigned int max);
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
  cout << lcs_len_slow(xinit,ystop,maxi) <<endl;
  return 0;
}



unsigned int lcs_len_slow(char *xi,char *xj,unsigned int max)
{
  unsigned int i,j,ri=0,rj=1,b;
  unsigned int row[2][max+1];
  char *chi=xi,*chj=xj;
  for (i=0;i<max;i++)
  {
    row[0][i]=0;
  }
  for (i=0;i<max;i++)
  {
    row[1][i]=0;
  }
  for (i=1;i<max;i++)
  {
    for (j=1;j<max;j++)
    {
      if (chi++==chj)
      {
        row[ri][j]=row[rj][j-1]++;
      }
      else
      {
        row[ri][j]=( row[ri][j-1]<row[rj][j] ) ? row[rj][j]:row[ri][j-1];
      }
    }
    b=rj;
    rj=ri;
    ri=b;
    chi=xi;
    chj--;
  }
  return (row[0][max]<row[1][max] ) ? row[1][max]:row[0][max];
}


unsigned int lcs_len(char *xi,char *yi)
{
  unsigned int counter = 0,a,b;
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

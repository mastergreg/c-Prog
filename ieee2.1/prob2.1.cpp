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



unsigned int lcs_len_slow(char *xi,char *xj,unsigned int maxe)
{
  unsigned int i,j,ri=0,rj=1,b;
  unsigned int row[2][maxe+1];
  unsigned int *rowi,*rowj,prev;
  memset(row,0,8*maxe+4);
  char *chi=xi,*chj=xj;
  
  for (i=1;i<=maxe;i++)
  {
    rowi=row[ri];
    rowj=row[rj];
    for (j=1;j<=maxe;j++)
    {
      if (*chi==*chj)
      {
        rowi++;
        *rowi=*rowj+1;
        rowj++;
      }
      else
      {
        prev=*rowi;
        rowi++;
        rowj++;
        *rowi=max(*rowj,prev);
        
      }
      chi++;
    }
    b=rj;
    rj=ri;
    ri=b;
    chi=xi;
    chj--;
  }
  return (row[0][maxe]<row[1][maxe] ) ? row[1][maxe]:row[0][maxe];
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

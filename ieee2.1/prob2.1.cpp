#include "palindrome.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
string make_teststring(string line,string astr);
vector< vector<int> > c(101, vector<int>(101,0));

int LCS(string X,string Y)
{
  if (Y.length() > X.length())
    swap(X,Y);
  int m = X.length(),n=Y.length();
  vector< vector<int> > c(2, vector<int>(n+1,0));
  int i,j;
  for (i=1;i<=m;i++)
  {
    for (j=1;j<=n;j++)
    {
      if (X[i-1]==Y[j-1])
      {
        c[1][j]=c[0][j-1]+1;
        break;
      }
      else
      {
        c[1][j]=max(c[1][j-1],c[0][j]);
        break;
      }
    }
    cout << "hi"<<endl;
//    for (j=1;j<=n;j++)
//      c[0][j]=c[1][j];
  }
  return (c[1][n]);
}
int maxIndex(int a[], int size);

int find_range(string fline,char c);
int main()
{
  size_t maxi;
  string anotherstring="",line,fileline;
  ifstream myfile("softlab.txt");
  getline (myfile,fileline);
  maxi=fileline.length();
  line=fileline;
  reverse(line.begin(),line.end());


  cout <<  LCS(line,fileline) << endl; 


}

int maxIndex(int a[], int size)
{
  int maxIndex = 0;
  for (int i=1; i<size; i++) 
  {
    if (a[i] > a[maxIndex]) 
    {
      maxIndex = i;
    }
  }
  return maxIndex;
}

int find_range(string fline,char c)
{
  return fline.rfind(c)-fline.find(c);
}

string make_teststring(string line,string astr)
{
  int i;
  string newstr="";
  for (i=0;i<52;i++)
  {
    if ((int)line.find(astr[i])!=-1) newstr+=astr[i];
  }
  cout << newstr << endl;
  return newstr;
}



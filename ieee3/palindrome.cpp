#include "palindrome.h"
bool ispalindrome(const char str[])
{
  const char *start,*end;
  int n = strlen(str);
  start=str;
  end=start+n*sizeof(char);
  int middle=n/2;
  int i;
  for (i=0;i<middle;i++)
  {
    if (start++!=end--)
    {
      return false;
    }
  }
  return true;
}

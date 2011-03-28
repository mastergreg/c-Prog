#include "palindrome.h"
bool ispalindrome(const char str[])
{
  int n = strlen(str);
  int middle=n/2;
  int i;
  for (i=0;i<middle;i++)
  {
    if (str[i]!=str[n-i-1])
    {
      return false;
    }
  }
  return true;
}

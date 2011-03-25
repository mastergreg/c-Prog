#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct list
{
  unsigned int prime;
  struct list *next;
};
typedef struct list ourlist;

int isprime(ourlist *,unsigned long);
ourlist * append_prime(ourlist *,int );
unsigned int so_smooth(ourlist *,unsigned long);

int main (int argc, char *argv[])
{
  unsigned int b;
  unsigned long counter,i,j;
  int smooth_numbs=0; 
  if (argc !=4)
  {
    printf("Usage: %s b i j\n",argv[0]);
    return 1;
  }
  sscanf(argv[1], "%u",  &b);
  sscanf(argv[2], "%lu", &i);
  sscanf(argv[3], "%lu", &j);
  ourlist *head,*end;
  head=(ourlist *)malloc(sizeof(ourlist));
  head->prime=2;
  head->next=NULL; 
  end=head;
  for(counter=3;counter<=j;counter+=2)
  {
    if (isprime(head,counter)==1)
    {
      end=append_prime(end,counter);
    }
  }
  for (counter=i;counter<=j;counter++)
  {
    if(so_smooth(head,counter)<=b) smooth_numbs++;
  }
  printf("%d\n",smooth_numbs);
  return 0;
}


unsigned int so_smooth(ourlist *head,unsigned long num)
{
  unsigned int max=0;
  ourlist *buffer=head;
  unsigned int primos=buffer->prime;
  while(primos<=num)
  {
    if(num%primos==0 && primos>max)
    {
      max=primos;
    }
    if (buffer->next==NULL)
    {
      break;
    }
    else
    {
      buffer=buffer->next;
      primos=buffer->prime;
    }
  }
  return max;
}





ourlist * append_prime(ourlist *end,int b)
{ 
  ourlist * new_element;
  new_element=(ourlist *)malloc(sizeof(ourlist));
  end->next=new_element;
  new_element->prime=b;
  new_element->next=NULL;
  return new_element;
}


int isprime(ourlist *start,unsigned long num)
{
  double root=sqrt(num);
  ourlist *buffer=start;
  while(buffer->prime<=root)
  {
    if ((num%(buffer->prime))==0)
    {
      return 0;
    }
    if (buffer->next==NULL)
    {
     break;
    }
    buffer=buffer->next;
  }
  return 1;
}

#ifndef FIBONACCI_H
#define FIBONACCI_H
#include "unlimitedsum.h"

int fib(int n)
{
  int fibLast = 1;
  int fibsecLast = 1;
  if (n <= 2)
   return fibLast;
 
  int res = 0;
  for(int i=3; i<=n; ++i)
  {
    res = fibLast + fibsecLast;
    int temp = fibLast;
    fibLast  = res;
    fibsecLast =  temp;
  }

  return res;
}

//caller is supposed to free returned ptr
char* fibUnlimited(int n)
{
  if (n <= 2)
  {
   char *res = (char*) malloc(2);
   res[0]='1'; res[1]='\0';
   return res;
  }
  
  char* fibLast = (char*)malloc(2);
  fibLast[0]='1'; fibLast[1]='\0';
  
  char* fibsecLast = (char*)malloc(2);
  fibsecLast[0]='1'; fibsecLast[1]='\0';
  
  char* retres = 0;
  char *temp = 0;
  for(int i=3; i<=n; ++i)
  {
    char* res=0;
    sumUnlimited(fibLast, fibsecLast, &res);
    if(temp==0||(strlen(fibLast) > strlen(temp)))
    {
      temp = (char*)realloc(temp, strlen(fibLast) + 1);
    }
    strcpy(temp,fibLast);
    
    if(strlen(res) > strlen(fibLast))
    {
      fibLast = (char*)realloc(fibLast, strlen(res)+1);
    }
    strcpy(fibLast,res);
   
    if(strlen(temp) > strlen(fibsecLast))
    {
      fibsecLast = (char*)realloc(fibsecLast,strlen(temp)+1); 
    }
    strcpy(fibsecLast,temp);

    if(retres ==0 || (strlen(res) > strlen(retres)))
    {
       retres = (char*)realloc(retres,strlen(res)+1);
    }
    strcpy(retres,res);

    if(res) free(res);
  }

  free(temp);
  free(fibLast);
  free(fibsecLast);

  return retres;
}

#endif

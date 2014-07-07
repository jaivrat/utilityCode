#ifndef UNLIMTEDSUM_H
#define UNLIMTEDSUM_H
#include <cstdlib>

//caller is supposed to free **out
int sumUnlimited(char * arr1, char* arr2, char **out)
{
  int len1   = strlen(arr1);
  int len2   = strlen(arr2);
  int outsz  = (len1>=len2?len1:len2)+1; //one extra to hold sum. Last one to hold null termination
  char* res  = (char*)malloc(outsz);
  memset(res,'\0',outsz);
  int i=len1-1;
  int j=len2-1;
  int outidx = outsz - 2;
  int carry = 0;
  int store = 0;
  while(i>=0 || j>=0)
  {
     int ival = (i>=0)?arr1[i] - '0':0;
     int jval = (j>=0)?arr2[j] - '0':0;
     int sum = ival + jval + carry;
     store = sum%10;
     res[outidx--] = '0' + store ;
     carry = (sum - store)/10;
     i = i -1;
     j = j -1;
  }

  if(carry>0)
  {
     if(outidx<0)
     {
       char * temp = (char*) malloc(++outsz);
       strcpy(temp+1,res);
       free(res);
       res = temp;
       outidx = outidx + 1;
     }
     res[outidx--] = '0' + carry ;
  }

  *out = res;
}

#endif

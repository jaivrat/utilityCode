#include "reverse.h"

#include <iostream>
#include <cstring>

void reverseWords(char * arr, int start, int last)
{
   reverse(arr,start,last);
   //std::cout << "Input to reverseWords >>" << arr << "<<<<\n";

   int idx = start;
   int tstart = start;
   while(idx<=last)
   {
     //   std::cout << "Got >" << arr[idx] << "<\n";
     if(isspace(arr[idx]))
     {
     	reverse(arr,tstart, idx-1);
        tstart = idx + 1;
     }
     idx = idx + 1;
   }
   reverse(arr,tstart, idx-1);
}

void reverse(char * arr, int start, int last)
{
  for(int i=start,j=last; i<j; ++i, --j)
  {
     char temp = arr[j];
     arr[j] = arr[i];
     arr[i] = temp;
  }
}

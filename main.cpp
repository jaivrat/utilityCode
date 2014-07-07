#include <iostream>
#include <string>

#include "reverse.h"
#include "fibonacci.h"
#include "unlimitedsum.h"

#include <cmath>

int main()
{

  //1. Test reverse declared in reverse.h

  //char arr[] = "T   A B";
  char arr[] = "Today is Wednesday";
  std::cout << "Original >" << arr << "<\n";
  reverseWords(arr,0,strlen(arr)-1);
  std::cout << "new >" << arr << "<\n";


  for(int i=0; i<300; ++i)
  {
    int f = fib(i);
    char *res = fibUnlimited(i);
    std::cout << "Fib(" << i << ")=" << f <<  "  safe=" << res << "\n";
    if(res) free(res);
  }


  char *res = 0;
  sumUnlimited("34878799", "1", &res);
  std::cout << "res=" << res << "\n";
  if(res) free(res);

  return(0);
}

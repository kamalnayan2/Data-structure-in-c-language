#include <stdio.h>
#include <string.h>
#include "cststack.h"
 int main()
{
   char str[]="IProgramX";
   printf("%s\n",str);
   int len = strlen(str);
   int i;

   for(i=0;i<len;i++)
        push(str[i]);

   for(i=0;i<len;i++)
      pop();
      
    return 0;
}
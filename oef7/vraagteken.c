#include <stdio.h>


int main(void){
   int a = 2;
   char * b = "";
   b = (a==1) ? "one" : "not one, but another number";
   printf("Uitkomst: %s\n",b);
}

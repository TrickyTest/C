#include <stdio.h>

int main(void){
	printf("Here goes:\n");
	for (unsigned long i=0;i<12345;i++){
		printf("\t= %04lx\n",i);
	}
	printf("Tadaaa!\n");
	return 0;
}


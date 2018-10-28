#include <stdio.h>
#include <math.h>

union abc { unsigned char b[8];
            long i;
};

union abc a;
union abc b;

int tceil(int j){
   int ret = ceil(j/50);
   if (ret<=0) ret=1;
   return ret;
}

int main(){
	for (int j=0;j<2000000;j+=tceil(j/50)){
		a.i=j;
		printf("%20li > ",a.i);
		printf("%3d %3d %3d %3d %3d %3d %3d %3d",a.b[0],a.b[1],a.b[2],a.b[3],a.b[4],a.b[5],a.b[6],a.b[7]);
		for (int k=0;k<8;k++) b.b[7-k]=a.b[k];
		printf(" < == > ");
                printf("%3d %3d %3d %3d %3d %3d %3d %3d",b.b[0],b.b[1],b.b[2],b.b[3],b.b[4],b.b[5],b.b[6],b.b[7]);
 		printf(" < %20li \n",b.i);
	}
	return 0;
}

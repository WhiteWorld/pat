#include <stdio.h>


long a[3],b[3],sum[3];

int main(){

	scanf("%ld.%ld.%ld",&a[2],&a[1],&a[0]);
	scanf("%ld.%ld.%ld",&b[2],&b[1],&b[0]);

	sum[0]=0;
	sum[1]=0;
	sum[2]=0;

	sum[0] = (a[0]+b[0])%29;
	a[1] += (a[0]+b[0])/29;

	sum[1] = (a[1]+b[1])%17;
	sum[2] = (a[1]+b[1])/17;

	sum[2] += (a[2]+b[2]);


	//sum[1] += (a[0]+b[0])/29;	


	printf("%ld.%ld.%ld\n",sum[2],sum[1],sum[0]);



	return 0;
}
#include <stdio.h>
#include <math.h>
#define N 1001
struct num
{
	float a;
	int flag;
};

struct num P[N]; 
int k;
int main(){
	for (int i = 0; i < N; ++i)
	{
		P[i].a = 0;
		P[i].flag = 0;
	}
	scanf("%d",&k);
	for (int i = 0; i < k; ++i)
	{	
		int n;
		float a;
		scanf("%d%f",&n,&a);
		P[n].a += a;
		P[n].flag = 1;
	}
	scanf("%d",&k);
	for (int i = 0; i < k; ++i)
	{	
		int n;
		float a;
		scanf("%d%f",&n,&a);
		P[n].a += a;
		P[n].flag = 1;
	}
	
	int count=0;
	for (int i = N-1; i >= 0 ; --i)
		if(P[i].flag == 1 && fabs(P[i].a) > 0.000001)
			count ++;
	//OUTPUT
	printf("%d",count);
	for (int i = N-1; i >= 0; --i)
		if(P[i].flag == 1 && fabs(P[i].a) > 0.000001)
			printf(" %d %.1f",i,P[i].a);
	return 0;
}

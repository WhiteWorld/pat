#include <stdio.h>
#include <cstdlib>
#include <math.h>
#define N 2002

float a[N],sum[N];
int n;
int main()
{
	for(int i=0;i<N;i++){
		sum[i]=0;
		a[i]=0;
	}

	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int it;
		float ft;
		scanf("%d%f",&it,&ft);
		a[it] = ft;
	}

	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int it;
		float ft;
		scanf("%d%f",&it,&ft);
		for(int j=0;j<N;j++){
				sum[it+j]+=a[j]*ft;
		}
	}
	int count =0;
	for(int i=0;i<N;i++){
		if(fabs(sum[i])>=0.05)
			count++;
	}
	printf("%d",count);
	for(int i=N-1;i>=0;i--){
		if(fabs(sum[i])>=0.05)
			printf(" %d %.1f",i,sum[i]);
	}
	//system("pause");
	return 0;
}
/*
Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 3 3.6 2 6.0 1 1.6
*/
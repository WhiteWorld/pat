#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define N 10002
int K;

int a[N];

int last[N],fisrt[N];

int max(int a,int b){
	return a>=b?a:b;
}

int main(){
	scanf("%d", &K);
	for(int i=0;i<K;i++)
		scanf("%d",&a[i]);

	last[0]=a[0];
	for(int i=1;i<K;i++)
		last[i] = max(last[i-1]+a[i],a[i]);

	// fisrt[K-1]=a[K-1];
	// for(int i=K-2;i>=0;i--)
	// 	fisrt[i] = max(fisrt[i+1]+a[i],a[i]);
	int max,index;
	max=-1;
	index = 0;
	for(int i=0;i<K;i++)
		if(last[i]>max){
			max=last[i];
			index = i;
		}
	if(max<0)
		printf("0 %d %d\n",a[0],a[K-1]);
	else{
		//printf("%d %d ",max,a[index]);
		int sum =0,end=0;
		for(int i=index;i>=0;i--){
			sum+=a[i];
			if(sum==max){
				end = i;
				break;
			}
		}
		printf("%d %d %d\n",max,a[end],a[index]);
	}

		




	return 0;
}

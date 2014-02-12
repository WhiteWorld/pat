/*浮点数是否为0的判断*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;


int main(){
	float a[1001];
	for(int i=0;i<1001;i++)
		a[i]=0.0;
	int k,ti;
	float tf;
	scanf("%d",&k);
	while(k--){
		scanf("%d%f",&ti,&tf);
		a[ti]=tf;
	}
	scanf("%d",&k);
	while(k--){
		scanf("%d%f",&ti,&tf);
		a[ti]+=tf;
	}
	int cnt=0;
	for(int i=0;i<1001;i++)
		if(fabs(a[i])>0.000001)
			cnt++;
	printf("%d",cnt);
	for(int i=1000;i>=0;i--)
		if(fabs(a[i])>0.000001)
			printf(" %d %.1f", i, a[i]);
	printf("\n");
	return 0;
}
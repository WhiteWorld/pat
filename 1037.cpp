#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

const int N=100005;

long long ans[N];
int a[N];
int b[N];
bool cmp(int a1,int a2){
	return a1 > a2;
}
int main(){
	int nc,np;
	scanf("%d",&nc);
	for(int i=0;i<nc;i++)
		scanf("%d",&a[i]);
	scanf("%d",&np);
	for(int i=0;i<np;i++)
		scanf("%d",&b[i]);
	std::sort(a,a+nc,cmp);
	std::sort(b,b+np,cmp);

	int za=nc;
	for(int i=0;i<nc;i++)
		if(a[i]<0){
			za=i;
			break;
		}
	int zb=np;
	for(int i=0;i<np;i++)
		if(b[i]<0){
			zb=i;
			break;
		}

	int index=0;
	long long sum=0;
	for(int i=0,j=0;i<za&&j<zb;i++,j++)
		//ans[index++]=a[i]*b[j];
		sum+=a[i]*b[j];
	for(int i=nc-1,j=np-1;i>=za&&j>=zb;i--,j--)
		//ans[index++]=a[i]*b[j];
		sum+=a[i]*b[j];
	printf("%lld\n",sum);
	system("PAUSE");
	return 0;
}

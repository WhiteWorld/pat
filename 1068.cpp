#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
const int M=102;
const int N=10004;

int a[N];
int sum;
int n,m;
int ans[N];
int dfs(int s){
	if(sum==m)
		return 1;
	if(sum>m)
		return 0;
	if(s==n-1)
		return 0;
	for(int i=s+1;i<n;i++){
		if(a[i]>m)
			break;
		if(a[i]+sum>m)
			break;
		sum+=a[i];
		ans[i]=1;
		int res=dfs(i);
		if(res)
			break;
		sum-=a[i];
		ans[i]=0;
	}
	if(sum==m)
		return 1;
	else
		return 0;
}

int main(){

	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

	std::sort(a,a+n);

	sum=0;
	if(dfs(-1)){
		int i;
		for(i=0;i<n;i++)
			if(ans[i])break;
		printf("%d",a[i]);//space
		for(int j=i+1;j<n;j++)
			if(ans[j])
				printf(" %d",a[j]);
		printf("\n");
	}else
		printf("No Solution\n");



	system("PAUSE");
	return 0;
}

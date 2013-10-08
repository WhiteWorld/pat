#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>



int n, m;

int a[1000];

int main(){
	scanf("%d%d",&n,&m);

	memset(a,0,sizeof(int)*505);
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		a[t]++;
	}
	int v1=-1;
	for(int v=1;v<1000&&v<=m-v;v++){
		if((v==m-v)&&(a[v]>1)){
			printf("%d %d\n",v,m-v);
			v1=v;
			break;
		}
		else if(a[v]>0&&a[m-v]>0&&(v!=m-v)){
			printf("%d %d\n",v,m-v);
			v1=v;
			break;
		}
	}
	if(v1==-1)
		printf("No Solution\n");



	return 0;
}

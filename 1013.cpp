#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define N 1001

int v[N];
int edge[N][N];
int n,m,k;
void dfs(int t){
	v[t]=1;
	for(int j=1;j<=n;j++)
		if(!v[j]&&edge[t][j]==1)
			dfs(j);

}


int main(){
	scanf("%d%d%d", &n,&m,&k);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		edge[a][b]=1;
		edge[b][a]=1;
	}
	for(int i=0;i<k;i++){
		memset(v,0,sizeof(int)*N);
		int t;
		scanf("%d",&t);
		v[t]=1;
		int num=0;
		for(int j=1;j<=n;j++){
			if(v[j]==0){
				dfs(j);
				num++;
			}
		}
		printf("%d\n", num-1);

	}



	return 0;
}

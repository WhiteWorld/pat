#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define N 10001

struct Node
{
	int visited;
	int num;
	int level;
	int id;
	/* data */
}node[N];

int edge[N][N]; 
int v[N];
int ans[N];
int n;
void dfs(int t){
	v[t]=1;
	for(int i=1;i<=n;i++)
		if(!v[i]&&edge[t][i]==1)
			dfs(i);
}
int get_level(int t){
	//printf("get_level:%d\n", t);
	v[t]=1;
	int max=0;
	for(int i=1;i<=n;i++){
		if(!v[i]&&edge[t][i]==1){
			int tmp=get_level(i);
			if(tmp+1>max)
				max=tmp+1;
		}
	}
	return max;
}
bool cmp(struct Node a,struct Node b){
	return a.level > b.level;
}
int main(){


	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		if(edge[a][b]==0){
			edge[a][b]=1;
			edge[b][a]=1;
			node[a].num++;
			node[b].num++;
		}
	}
	int num=0;
	memset(v,0,sizeof(v));
	for (int i = 1; i <= n; ++i)
	{
		if(!v[i]){
			dfs(i);
			num++;
		}
	}
	//
	if(num>1){
		printf("Error: %d components\n",num);
	}else{
		for(int i=1;i<=n;i++){
			node[i].level=0;
			node[i].id=i;
			if(node[i].num==1){
				//printf("i:%d\n", i);
				memset(v,0,sizeof(int)*N);
				node[i].level=get_level(i);
			}
		}
		std::sort(node+1,node+n,cmp);

		
		int d=node[1].level;
		for(int i=1;i<=n;i++){
			//printf("Dep:%d\n",node[i].level);
			if(node[i].level==d)
				printf("%d\n",node[i].id);
		}
	}
	return 0;
}

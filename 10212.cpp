#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define N 10001

// struct Node
// {
// 	int num;
// 	//int level;
// 	//int id;
// }node[N];

int node[N];
int edge[N][N]; 
bool v[N];
int n;
int parent[N];

int find(int a){
	while(a!=parent[a])
		a=parent[a];
	return a;
}
int merge(int a,int b){
	parent[a]=b;
}
int get_level(int t){

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
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		parent[i]=i;

	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		if(edge[a][b]==0){
			edge[a][b]=1;
			edge[b][a]=1;
			node[a]++;
			node[b]++;
			int ap=find(a);
			int bp=find(b);
			if(ap!=bp)
				merge(ap,bp);
		}
	}


	int num=0;
	
	for(int i=1;i<=n;i++)
		if(parent[i]==i)
			num++;

	if(num>1){
		printf("Error: %d components\n",num);
	}else{
		int max=0;
		for(int i=1;i<=n;i++){
			//node[i].level=0;
			//node[i].id=i;
			if(node[i]==1){
				memset(v,0,sizeof(bool)*N);
				node[i]=get_level(i);
				if(node[i]>max)
					max=node[i];
			}else
				node[i]=0;

		}
		//int d=node[1].level;
		for(int i=1;i<=n;i++){
			if(node[i]==max)
				printf("%d\n",i);
		}
	}
	return 0;
}

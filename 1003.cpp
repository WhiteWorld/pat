#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
const int N = 502;
const int INF = 0x7fffffff;
using namespace std;



int n,m,c1,c2;
int teams[N];
int edge[N][N];
int dist[N];
bool used[N];

void Dijkstra(int s,int d){
	for(int i=0;i!=n;++i)
		dist[i]=INF;
	dist[s]=0;
	for(int k=0;k!=n;k++){
		int min=INF;
		int index;
		for(int i=0;i!=n;++i)
			if(!used[i]&&dist[i]<min){
				min=dist[i];
				index=i;
			}
		used[index]=true;
		if(index==d)
			break;
		for(int i=0;i!=n;i++)
			if(!used[i]&&edge[index][i]!=-1&&edge[index][i]+dist[index]<dist[i])
				dist[i]=edge[index][i]+dist[index];
	}
}
int pathnum=0,maxnum=-1;
void dfs(int s,int d,int curdis,int curnum){
	if(s==d){
		if(curdis==dist[d]){
			pathnum++;
			if(curnum>maxnum)
				maxnum=curnum;
		}
		return;
	}
	if(curdis>=dist[d])
		return;
	for(int i=0;i!=n;i++)
		if(!used[i]&&edge[s][i]!=-1&&curdis+edge[s][i]<=dist[d]){
			used[i]=true;
			int tcurdis=curdis+edge[s][i];
			dfs(i,d,tcurdis,curnum+teams[i]);
			used[i]=false;
		}
	return;
}


int main()
{
    scanf("%d %d %d %d", &n, &m, &c1, &c2);
	for(int i=0;i!=n;i++){
		int t;
		scanf("%d",&t);
		teams[i]=t;
	}
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			edge[i][j]=-1;
	for(int i=0;i!=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		edge[a][b]=c;
		edge[b][a]=c;
	}
	memset(used,0,sizeof(used));
	Dijkstra(c1,c2);
	memset(used,0,sizeof(used));
	used[c1]=true;
	dfs(c1,c2,0,teams[c1]);
	printf("%d %d\n",pathnum,maxnum);
    return 0;
}

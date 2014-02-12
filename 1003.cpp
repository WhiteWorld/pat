#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
const int N = 502;
const int INF = 0x7fffffff;
using namespace std;


void Dijkstra(int s,int d, int n, int *dist, bool *used, int edge[N][N]){
	/*初始化保存源点到所有点的数组*/
	for(int i=0;i!=n;++i)
		dist[i]=INF;
	dist[s]=0;

	/*依次把n个点加入到集合中，集合初始为空，加入的第一个点肯定是s源点*/
	for(int k=0;k!=n;k++){
		int min=INF;
		int index;//保存要加入的点
		/*在未加入集合的点中找到dist中最小的点*/
		for(int i=0;i!=n;++i)
			if(!used[i]&&dist[i]<min){
				min=dist[i];
				index=i;
			}
		used[index]=true;//标记加入集合
		/*如果找到终点则返回*/
		if(index==d)
			break;
		/*更新dist数组*/
		for(int i=0;i!=n;i++)
			if(!used[i]&&edge[index][i]!=-1&&edge[index][i]+dist[index]<dist[i])
				dist[i]=edge[index][i]+dist[index];
	}
}
int pathnum=0,maxnum=-1;
/*查找最短路径的条数，记录最大的权值*/
void dfs(int s,int d,int n,int curdis,int curnum, int *dist, int edge[N][N],bool *used,int *teams){
	if(s==d){
		if(curdis==dist[d]){//找到一条最短路径
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
			dfs(i,d,n,tcurdis,curnum+teams[i],dist,edge,used,teams)   ;
			used[i]=false;
		}
	return;
}


int main()
{
	int n,m,c1,c2;
	int teams[N];
	int edge[N][N];
	int dist[N];
	bool used[N];
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
	Dijkstra(c1,c2,n,dist,used,edge);

	memset(used,0,sizeof(used));
	used[c1]=true;
	dfs(c1,c2,n,0,teams[c1],dist,edge,used,teams);
	printf("%d %d\n",pathnum,maxnum);
    return 0;
}
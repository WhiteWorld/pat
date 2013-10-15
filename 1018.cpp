/*
#include <stdio.h>
#include <string.h>
#define MAX 200000000
int g[502][502];
int in[502];

/////////////////******dij算法的细节没记牢，另外，dfs重用dij的v[]是个好剪枝//////////////////////////////////
//不知道有没有dij算法直接一遍求出结果的方法

int C,N,P,A;
int trace[502];
int L;
int v[502];//dij
int d[502];

int lentoP;
int stack[502];
int top;

int dijstra()
{
	int i,j;
	int minn,next,last;

	memset(v,0,sizeof(v));
	memset(d,-1,sizeof(d));
	minn = MAX;

	for(i=1;i<=N;i++)
	{
		if(g[0][i]!=-1)
		{
			d[i] = g[0][i];
			if(d[i]<minn)
			{
				minn = d[i];
				next = i;
			}
		}
	}

	while(1)
	{
		v[next] = 1;
		if(next == P)
			return d[P];

		last = next;
		minn = MAX;
		for(i=1;i<=N;i++)
		{
			if(v[i])
				continue;
			if(g[last][i]!=-1 && (d[i]==-1||g[i][last] + d[last] < d[i]))////这里要判断d[i]==-1，记住咯
				d[i] = g[i][last] + d[last];
			if(d[i]!=-1&&d[i]<minn)
			{
				minn = d[i];
				next = i;
			}
		}
		if(minn == MAX)
			printf("error");
	}
}

int min_need,min_return;

void dfs(int from,int len,int need,int remain)
{
	int i;
	if(len > lentoP || need>min_need )
		return;

	if(from!=0)
	{//更新need和remain值
		if(in[from] > A)
			remain += in[from] - A;
		else
		{
			if(remain > A - in[from])
				remain -=(A - in[from]);
			else
			{
				need += (A - in[from] - remain);
				remain = 0;
			}
		}
	}

	if(from == P && len == lentoP)
	{
		if(need < min_need || (need==min_need&&remain<min_return))
		{
			int j;
			min_need = need;
			min_return = remain;
			for(j=0;j<top;j++)
				trace[j] = stack[j];

			L = top;
		}	
		return;
	}
	
	for(i=1;i<=N;i++)
		if(v[i]&&g[from][i]!=-1)
		{
			v[i] = 0;
			stack[top++] = i;
			dfs(i, len + g[from][i],need,remain);
			top--;
			v[i] = 1;
		}
}

void DFS()//最短路径的栈保留在trace数组中
{//这里面重用dij的v[],意义反过来（0代表已访问），即只考虑dij中加入集的点，其他点在这里视为已访问
	int i;
	min_need = MAX;
	min_return = MAX;
	top = 1;
	stack[0] = 0;
	v[0] = 0;
	dfs(0,0,0,0);
	printf("%d %d",min_need, trace[0]);
	for(i=1;i<L;i++)
		printf("->%d",trace[i]);
	printf(" %d\n",min_return);
}


void fun()
{
	int n,r;
	lentoP = dijstra();
	DFS();
}

int main()
{
	int i,M,a,b,c;
	while(scanf("%d%d%d%d",&C,&N,&P,&M)!=EOF)
	{
		A = C/2;
		memset(g,-1,sizeof(g));
		for(i=1;i<=N;i++)
			scanf("%d",in + i);
		while(M--)
		{
			scanf("%d%d%d",&a,&b,&c);
			g[a][b] = g[b][a] = c;
		}
		fun();
	}
	return 0;
}
*/

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
const int N = 502;
const int INF = 0x7fffffff;
using namespace std;



int cmax,n,sp,m;
int bikes[N];
int edge[N][N];
int dist[N];
bool used[N];

void Dijkstra(int s,int d){
	for(int i=0;i!=n+1;++i)
		dist[i]=INF;
	dist[s]=0;
	for(int k=0;k!=n+1;k++){
		int min=INF;
		int index;
		for(int i=0;i!=n+1;++i)
			if(!used[i]&&dist[i]<min){
				min=dist[i];
				index=i;
			}
		used[index]=true;
		if(index==d)
			break;
		for(int i=0;i!=n+1;i++)
			if(!used[i]&&edge[index][i]!=-1&&edge[index][i]+dist[index]<dist[i])
				dist[i]=edge[index][i]+dist[index];
	}
}
int pathnum=0,maxnum=-1;
int minneed,minremain;
void dfs(int s,int dis,int need,int remain){
	cout<<"s:"<<s<<endl;
	if(s==sp){
		if(dis==dist[sp]){
			//pathnum++;
			if(need<minneed){
				minneed=need;
				minremain=remain;
			}
			else if(need==minneed&&remain<minremain){
				minneed=need;
				minremain=remain;
			}
		}
		return;
	}
	if(dis>dist[sp])
		return;

	for(int i=1;i!=n+1;i++)
		if(!used[i]&&edge[s][i]!=-1){
			used[i]=true;
			int tcurdis=dis+edge[s][i];
			int tremain,tneed;

			if(remain+bikes[i]>=cmax)
				tremain=remain+bikes[i]-cmax;
			else{
				tneed=need+cmax-remain-bikes[i];
				tremain=0;
			}
			dfs(i,tcurdis,tneed,tremain);
			used[i]=false;
		}
	return;
}


int main()
{
    scanf("%d %d %d %d", &cmax, &n, &sp, &m);
	bikes[0]=0;
	cmax/=2;
	for(int i=1;i!=n+1;i++){
		int t;
		scanf("%d",&t);
		bikes[i]=t;
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
	Dijkstra(0,sp);
	printf("%d\n",dist[sp]);
	minneed=INF;
	minremain=INF;
	//memset(used,0,sizeof(used));
	used[0]=true;
	dfs(0,sp,0,0);
	printf("%d %d\n",minneed,minremain);
	system("PAUSE");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <math.h>
#include <algorithm>
using namespace std;

#define N 502
#define INF 0x7fffff
int cmax,n,sp,m;

int bikes[N];
int edge[N][N];
int dist[N];
int used[N];
int back[N];
int pre[N];
int send[N];
int getback(int i){
	return cmax-bikes[i];
}
void Dijkstra(int s,int d){
	for(int i=0;i<=n;i++){
		dist[i]=INF;
		back[i]=INF;
	}
	dist[s]=0;
	back[s]=0;
	send[s]=0;
	//used[s]=1;
	for(int i=0;i<=n;i++){
		int mintime=INF;
		int minback=INF;
		int index;
		for(int j=0;j<=n;j++)
			if(!used[j]&&dist[j]<=mintime){
				if(dist[j]<mintime){
					index=j;
					minback=back[j];
					mintime=dist[j];
				}else if(back[j]<minback){			
					index=j;
					minback=back[j];
					mintime=dist[j];
				}
			}
		used[index]=1;
		//printf("index :%d\n",index);
		if(index==d)
			break;
		for(int j=0;j<=n;j++)
			if(!used[j]&&edge[index][j])
				if(dist[index]+edge[index][j]<dist[j]){
					//if(back[index]+getback(j)<back[j])
					//back[j]=back[index]+getback(j);
					dist[j]=dist[index]+edge[index][j];
					pre[j]=index;
				}else if(dist[index]+edge[index][j]==dist[j] && back[index]+getback(j)<back[j]){
					back[j]=back[index]+getback(j);
					pre[j]=index;
				}
	}
}

int main(){
	scanf("%d%d%d%d",&cmax,&n,&sp,&m);
	bikes[0]=cmax/2;
	for(int i=1;i<=n;i++)
		scanf("%d",&bikes[i]);
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		edge[a][b]=c;
		edge[b][a]=c;
	}

	Dijkstra(0,sp);
	//int send=0,rec=0;
	//if(back[sp]>=0){
	//	send=0;
	//	rec=back[sp];
	//}else{
	//	send=0-back[sp];
	//	rec=0;
	//}
	//printf("%d 0",send);

	stack<int> st;
	st.push(sp);
	int t=pre[sp];
	int sum=bikes[sp];
	int cnt=1;
	while(t!=0){
		cnt++;
		sum+=bikes[t];
		st.push(t);
		t=pre[t];
	}
	int send=0;
	int rec=0;
	if(cnt*5>sum)
		send=cnt*5-sum;
	else
		rec=sum-cnt*5;
	printf("%d 0",send);
	while(!st.empty()){
		int top;
		top=st.top();
		st.pop();
		printf("->%d",top);
	}
	printf(" %d\n",rec);
	system("PAUSE");
	return 0;
}

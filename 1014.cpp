#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include <queue>
using namespace std;
#define K 1003
#define INF 0x7fffffff
typedef struct 
{
	int process;
	int begin;
	int leave;
}Node;
Node node[K];
int query[K];
int cap[21];

queue<int> waitq[21];

int main()
{
	int time[21];
	int n,m,k,q;
	cin>>n>>m>>k>>q;
	for(int i=1;i<=k;i++){
		cin>>node[i].process;
		node[i].begin=8*60;
	}
	for(int i=1;i<=q;i++)
		cin>>query[i];
	
	for(int i=0;i<n;i++){
		time[i]=0;
	}

	for(int i=1;i<=k;i++){
		int min=INF;
		int index;
		for(int j=0;j<n;j++)
			if(waitq[j].size()<min){
				min=waitq[j].size();
				index=j;
			}
		if(min==m){//找空出一个位最早的窗口
			min=INF;
			for(int j=0;j<n;j++)
				if(node[waitq[j].front()].leave<min){
					min=node[waitq[j].front()].leave;
					index=j;
				}
			time[index]-=node[waitq[index].front()].process;
			for(int j=i;j<=k;j++)
				node[j].begin=node[waitq[index].front()].leave;
			waitq[index].pop();
			waitq[index].push(i);
			node[i].leave=time[index]+node[i].process+node[i].begin;
			time[index]+=node[i].process;
		}else{//找到最短的窗口
			waitq[index].push(i);
			node[i].leave=time[index]+node[i].process+node[i].begin;
			time[index]+=node[i].process;
		}
	}
	for(int i=1;i<=q;i++)
		if(node[query[i]].leave-node[query[i]].process<17*60)
			printf("%02d:%02d\n",node[query[i]].leave/60,node[query[i]].leave%60);
		else
			printf("Sorry\n");
	system("PAUSE");
	return 0;
}
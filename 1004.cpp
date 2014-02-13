#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
const int N = 100;
using namespace std;

typedef struct {
	int pid;
	int level;
	bool have_child;
}Node;
Node node[N];


int get_level(int id){
	int pid=node[id].pid;
	if(node[pid].level!=-1)
		return node[pid].level+1;
	else 
		return get_level(pid)+1;
}
int main()
{
	int n,m;
	int l[N];//hash level
	scanf("%d%d",&n,&m);
	for(int i=1;i<N;i++){
		node[i].level=-1;
		node[i].have_child=false;
		l[i]=0;
	}
	node[1].pid=-1;//root
	node[1].level=1;
	for(int i=0;i<m;i++){
		char str[3];
		int pid,num;
		scanf("%s%d", str,&num);
		pid=(str[0]-'0')*10+str[1]-'0';
		node[pid].have_child=true;
		while(num--){
			scanf("%s",str);
			int cid;
			cid=(str[0]-'0')*10+str[1]-'0';
			node[cid].pid=pid;
		}
	}
	int maxlevel=-1;
	for(int i=1;i<=n;i++){
		if(node[i].level==-1)
			node[i].level=get_level(i);
		if(!node[i].have_child)
			l[node[i].level]++;
		if(node[i].level>maxlevel)
			maxlevel=node[i].level;
	}
	printf("%d",l[1]);
	for(int i=2;i<=maxlevel;i++)
		printf(" %d",l[i]);
	//system("Pause");
    return 0;
}
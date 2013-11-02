#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

const int N = 100005;

typedef struct{
	int key;
	int address;
	int next;
	int inlist;
}Node;

Node node[N];
Node lnode[N];
int hash[N];
bool cmp(Node a,Node b){
	return a.key < b.key;
}
int main(){
	int n,head,tail;
	scanf("%d%d",&n,&head);

	if(head == -1){
		printf("0 -1\n");
		return 0;
	}


	memset(hash,0,sizeof(hash));
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&node[i].address,&node[i].key,&node[i].next);
		hash[node[i].address]=i;
		node[i].inlist = 0;
		if(node[i].next == -1)
			tail=node[i].address;
	}
	int t=hash[head];
	node[t].inlist=1;
	while(node[t].next!=-1){
		t=hash[node[t].next];

		node[t].inlist=1;
	}
	int index=0;
	for(int i=0;i<n;i++){
		if(node[i].inlist){
			lnode[index].address = node[i].address;
			lnode[index].key = node[i].key;
			index++;
		}
	}

	std::sort(lnode,lnode+index,cmp);

	printf("%d %05d\n",index,lnode[0].address);

	for(int i=0;i<index-1;i++)
		printf("%05d %d %05d\n",lnode[i].address,lnode[i].key,lnode[i+1].address);
	printf("%05d %d %d\n",lnode[index-1].address,lnode[index-1].key,-1);


	system("PAUSE");
	return 0;
}

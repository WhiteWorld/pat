#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

struct Node{
	//int id;//1~99
	int father;
	int child_num;
	int level;
};
struct Node node[100];
int n,m;
int maxlevel;
void update(int id){
	for(int i=2;i<100;i++)
		if(node[i].father>0&&node[i].father==id){
			node[i].level = node[id].level+1;
			if(node[i].child_num>0)
				update(i);
			else{
				if(node[i].level>maxlevel)
					maxlevel = node[i].level;
			}
		}
}

int main(){
	maxlevel = -1;
	node[1].level=0;
	node[1].child_num=0;
	node[1].father=-1;

	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int id,k;
		scanf("%d%d",&id,&k);
		node[id].child_num=k;
		for(int j=0;j<k;j++){
			int tid;
			scanf("%d",&tid);
			node[tid].father = id;
		}
	}
	update(1);
	if(n==1)
		printf("1");
	else
		printf("0");
	for(int i=1;i<=maxlevel;i++){
		int sum=0;
		for(int j=0;j<100;j++)
			if(node[j].level==i&&node[j].child_num==0)
				sum++;
		printf(" %d",sum);
	}

	/*
	for(int i=2;i<100;i++)
		if(node[i].father>0){

		}
		*/
	//printf("%02d  %d",id,k);
	system("PAUSE");
	return 0;
}
/*
update_level(int id)

*/
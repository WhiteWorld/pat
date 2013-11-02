#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


const int N = 1002;
int np,ng;
int index=0;
typedef struct {
	int id;
	int weight;
	int rank;
}Info;
Info info[N];
Info r[N];
Info infot[N];


void handle(int len){
	
	if(len==1){
		r[len-1].rank=1;
		info[index].id=r[len-1].id;
		info[index].rank = r[len-1].rank;
		info[index].weight  = r[len-1].weight;
		return;
	}


	int g = len/ng;
	int group;
	if(len%ng!=0)
		group=g+1;
	else
		group = g;
	for(int i=0;i<g;i++){
		int max = -1;
		for(int j=i*ng;j<(i+1)*ng;j++)
			if(r[j].weight>max){
				max=r[j].weight;
			}
		for(int j=i*ng;j<(i+1)*ng;j++)
			if(r[j].weight!=max)
				r[j].rank=group+1;
	}
	if(len%ng!=0){
		int max = -1;
		for(int i=g*ng;i<len;i++)
			if(r[i].weight>max)
				max=r[i].weight;
		for(int i=g*ng;i<len;i++)
			if(r[i].weight!=max)
				r[i].rank=group+1;
	}
	int indext=0;
	for(int i=0;i<len;i++)
		if(r[i].rank){
			info[index].id=r[i].id;
			info[index].rank = r[i].rank;
			info[index].weight = r[i].weight;
			index++;
		}else{
			infot[indext].id=r[i].id;
			infot[indext].rank = r[i].rank;
			infot[indext].weight = r[i].weight;
			indext++;
		}
	for(int i=0;i<indext;i++)
	{
		r[i].id = infot[i].id;
		r[i].rank = infot[i].rank;
		r[i].weight = infot[i].weight;
	}
	handle(indext);
}

bool cmp(Info a,Info b){
	return a.id < b.id;
}
int main(){

	scanf("%d%d",&np,&ng);
	for(int i=0;i<np;i++){
		int t;
		cin>>info[i].weight;
		info[i].id=i;
	}

	for(int i=0;i<np;i++){
		int t;
		cin>>t;
		r[i].id = info[t].id;
		r[i].weight = info[t].weight;
	}
	handle(np);

	sort(info,info+np,cmp);
	for(int i=0;i<np-1;i++)
		printf("%d ",info[i].rank);
	printf("%d\n",info[np-1].rank);
	system("PAUSE");
	return 0;
}

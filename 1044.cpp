#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

const int M=100005;
int n,m;
int chain[M];
struct Node {
	int begin;
	int end;
	int sum;
}node[M];
bool cmp(struct Node n1,struct Node n2){
		
	if(n1.sum==n2.sum)
		return n1.begin < n2.begin;
	else
		return n1.sum < n2.sum;
}
int main(){
	scanf("%d%d",&n,&m);

	node[0].begin=0;
	node[0].end=0;
	node[0].sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&chain[i]);
		node[i].begin=i;
	}
	for(int i=1;i<=n;i++){
		
		if(i>node[i-1].end){
			int sum=0;
			int flag=0;
			for(int j=i;j<=n;j++){
				sum+=chain[j];
				if(sum>=m){
					flag=j;
					break;
				}
			}
			if(flag)
				node[i].end=flag;
			else
				node[i].end=n;
			node[i].sum = sum;
		}else{
			int sum=node[i-1].sum-chain[i-1];
			
			if(sum>=m||node[i-1].end==n){
				node[i].end = node[i-1].end;
				node[i].sum = sum;
			}else{
				int flag=0;
				for(int j=node[i-1].end+1;j<=n;j++){
					sum+=chain[j];
					if(sum>=m){
						flag=j;
						break;
					}
				}
				if(flag)
					node[i].end=flag;
				else
					node[i].end=n;
				node[i].sum = sum;
			}

		}	
	}

	std::sort(node+1,node+n+1,cmp);
	//int first=node[1].sum;
	int flag=0;
	int i;
	for(i=1;i<=n;i++)
		if(node[i].sum>=m)
			break;
	for(int j=i;j<=n;j++)
		if(node[j].sum == node[i].sum)
			printf("%d-%d\n",node[j].begin, node[j].end);


	system("PAUSE");
	return 0;
}

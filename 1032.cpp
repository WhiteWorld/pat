#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

const int N = 100005;

int pre[N];
int main(){
	int w1,w2,n;
	scanf("%d%d%d",&w1,&w2,&n);
	for(int i=0;i<n;i++){
		int addr,next;
		char ch;
		scanf("%d %c %d",&addr,&ch,&next);
		if(next!=-1)
			pre[next]++;
	}
	int flag=0,index;
	for(int i=0;i<N;i++)
		if(pre[i]==2){
			flag=1;
			index=i;
		}
	if(w1==w2){
		printf("%05d\n",w2);
		return 0;
	}
	if(flag)
		printf("%05d\n",index);
	else{
		printf("-1\n");
	}
	system("PAUSE");
	return 0;
}

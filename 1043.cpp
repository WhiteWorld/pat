#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

#define N 1002

int out[N];



int a[N];
int n;
int flag;
int cnt;
int get_root(int s,int t){
	int ret=0;
	if(s>t)
		return 0;
	if(s==t){
		out[cnt++]=a[s];
		return 0;
	}
	if(flag==0){
		int j=t+1;
		for(int i=s+1;i<=t;i++)
			if(a[i]>=a[s]){
				j=i;
				break;
			}
		ret=get_root(s+1,j-1);
		if(ret==-1)
			return -1;
		for(int i=j;i<=t;i++)
			if(a[i]<a[s]){
				return -1;
			}
		ret = get_root(j,t);
		if(ret==-1)
			return -1;
		out[cnt++]=a[s];
	}else{
		int j=t+1;
		for(int i=s+1;i<=t;i++)
			if(a[i]<a[s]){
				j=i;
				break;
			}
		ret=get_root(s+1,j-1);
		if(ret==-1)
			return -1;

		for(int i=j;i<=t;i++)
			if(a[i]>=a[s]){
				return -1;
			}
		ret = get_root(j,t);
		if(ret==-1)
			return -1;
		out[cnt++]=a[s];
	}
}
int main(){
	cnt=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	if(a[0]<=a[1])
		flag=1;//right->left->root
	else
		flag=0;
	//q.push(a[0]);
	int ret;
	ret = 0;
	ret=get_root(0,n-1);
	if(ret==-1){
		printf("NO\n");
	}else{
		printf("YES\n%d",out[0]);
		for(int i=1;i<cnt;i++)
			printf(" %d",out[i]);
	}
	//system("PAUSE");
	return 0;
}

/*
Sample Input 1:
7
8 6 5 7 10 8 11
Sample Output 1:
YES
5 7 6 8 11 10 8
Sample Input 2:
7
8 10 11 8 6 7 5
Sample Output 2:
YES
11 8 10 7 5 6 8
Sample Input 3:
7
8 6 8 5 10 9 11
Sample Output 3:
NO
*/
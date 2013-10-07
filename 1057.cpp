#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>

#define N 100005
int n;
int p;

int stack[N];
int flag[N];

void push(int data){
	stack[p]=data;
	p++;
	flag[data]++;
}
int pop(void){
	if(p<=0){
		return -1;
	}
	p--;
	flag[stack[p]]--;
	return stack[p];
}

int PeekMedian(){
	if(p<=0)
		return -1;
	int m;
	m = p%2 ? (p+1)/2:p/2;
	int j=0;
	for(int i=0;i<N;i++)
		if(flag[i]>0){
			j++;
			if(j==m)
				return i;
		}
	return -1;
}

int main(){

	scanf("%d",&n);
	p=0;
	memset(flag,0,sizeof(int)*N);
	for(int i=0;i<n;i++){
		char str[15];
		scanf("%s",str);
		int len=strlen(str);
		if(len==3){
			int ret;
			ret=pop();
			if(ret<0)
				printf("Invalid\n");
			else
				printf("%d\n",ret);
		}else if(len == 4){
			int data;
			scanf("%d",&data);
			push(data);
		}else{
			int ret;
			ret=PeekMedian();
			if(ret<0)
				printf("Invalid\n");
			else
				printf("%d\n",ret);			
		}
	}
	return 0;
}

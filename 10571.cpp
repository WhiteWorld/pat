#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
#define Maxval 100009
int tree[Maxval+1];
int stack[Maxval+1];
void update(int idx,int val){
	while(idx<Maxval){
		tree[idx]+=val;
		idx+=(idx&-idx);
	}
}
int read(int idx){
	int sum=0;
	while(idx>0){
		sum+=tree[idx];
		idx-=(idx&-idx);
	}
	return sum;
}
int find_cumulate(int cumfre){
	int low=0,high=Maxval,mid;
	while(low<high-1){
		if((low+high)&1==1)
			mid=(low+high-1)/2;
		else
			mid=(low+high)/2;
		int sum=read(mid);
		if(sum>=cumfre)
			high=mid;
		else
		  	low=mid;
	}
	return high;
}
int main(){
	int n,i;
	char str[20];
	scanf("%d",&n);
	long tmp,top;
	memset(tree,0,Maxval*sizeof(int));
	memset(stack,0,Maxval*sizeof(int));
	top=0;
	for(i=0;i<n;i++){
		scanf("%str",str);
		if(str[1]=='o'){//POP
			if(top>0){
				tmp=stack[top--];
				printf("%d\n",tmp);
				update(tmp,-1);
			}
			else
				printf("Invalid\n");
		}
		else if(str[1]=='u'){//push
			cin>>tmp;
			stack[++top]=tmp;
			update(tmp,1);
		}
		else if(str[1]=='e'){//media
			if(top>0){
				if(top&1==1)
					tmp=(top+1)/2;
				else
					tmp=top/2;
				tmp=find_cumulate(tmp);
				printf("%d\n",tmp);
			}
			else
				printf("Invalid\n");
		}
		else{
			printf("Invalid\n");
		}
	}
	return 0;
}

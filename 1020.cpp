#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
#define N 32
int n;
int post[N],in[N];

struct Root {
	int root;
	int pbegin;
	int ibegin;
	int len;
};

queue<struct Root> q;

void find_child(struct Root r, struct Root *left, struct Root *right){
	int i,j,index;

	if(r.len==1){
		left->root = 0;
		right->root = 0;
		return;
	}

	for(i=r.ibegin;i<r.ibegin+r.len;i++)
		if(in[i]==r.root)
			break;
	index = i - r.ibegin;

	for(j=r.pbegin+index-1;j>=r.pbegin;j--)
		if(post[j]!=0)
			break;
	if(j<r.pbegin)
		left->root = 0;
	else{
		left->root = post[j];
		post[j] = 0;
		left->pbegin = r.pbegin;
		left->ibegin = r.ibegin;
		left->len = index;
	}

	for(j=r.pbegin+r.len-1;j>=r.pbegin+index;j--)
		if(post[j]!=0)
			break;
	if(j<r.pbegin+index)
		right->root = 0;
	else{
		right->root = post[j];
		post[j]=0;
		right->pbegin = r.pbegin+index;
		right->ibegin = r.ibegin + index+1;
		right->len = j-right->pbegin+1;
	}

}


int main(){

	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&post[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&in[i]);

	struct Root r;
	r.root = post[n-1];
	r.pbegin = 0;
	r.ibegin = 0;
	r.len = n;
	printf("%d",r.root);
	q.push(r);
	post[n-1]=0;
	

	while(!q.empty()){
		struct Root r = q.front();
		q.pop();
		//printf("%d[%d--%d]\n",r.root,r.begin,r.len);
		struct Root left,right;
		find_child(r,&left,&right);
		if(left.root>0){
			printf(" %d",left.root);
			q.push(left);
		}
		if(right.root>0){
			printf(" %d",right.root);
			q.push(right);
		}
	}
	//system("PAUSE");
	return 0;
}

/*
Sample Input:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
Sample Output:
4 1 6 3 5 7 2
*/
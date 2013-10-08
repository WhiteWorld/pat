#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
using namespace std;

#define N 1001

int n;
int a[N];
bool cmp(int a,int b){
	return a < b;
}
int root(int begin,int end){
	if(begin==end)
		return begin;

	int num = end - begin + 1;
	int k,root;//
	k=0;
	int a=1;
	while(num>0){
		num-=a;
		a*=2;
		k++;
	}
	a/=2;
	num+=a;
	if(num<=a/2)
		root= end-((end-begin+1)-num-1)/2;
	else
		root = end-((end-begin+1)-num-1)/2-(num-a/2);
	return root;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n,cmp);
	int r=root(0,n-1);
	printf("%d",a[r]);
	queue<int> q;
	q.push(r);
	a[r]=-1;
	while(!q.empty()){
		int left,right;
		int r;
		r=q.front();
		q.pop();
		a[r]=-1;
		left=r-1;
		right=r+1;
		while(left>=0){
			if(a[left]<0)
				break;
			left--;
		}
		left++;
		while(right<=n-1){
			if(a[right]<0)
				break;
			right++;
		}
		right--;

		//printf("left:%d right:%d\n",left,right );

		if(left!=r){
			q.push(root(left,r-1));
			printf(" %d",a[root(left,r-1)]);
		}

		if(right!=r){
			q.push(root(r+1,right));
			printf(" %d", a[root(r+1,right)]);
		}
	}
	printf("\n");
	return 0;
}

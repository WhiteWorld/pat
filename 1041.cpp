#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define N 100005

int n;
int a[N];
int hash[10001];
int main(){
	scanf("%d", &n);

	for(int i=0;i<n;i++){
		int t;
		scanf("%d", &t);
		a[i]=t;
		hash[t]++;
	}
	int flag=0;
	for(int i=0;i<n;i++)
		if(hash[a[i]]==1){
			printf("%d\n",a[i]);
			flag=1;
			break;
		}
	if(flag==0)
		printf("None\n");






	return 0;
}

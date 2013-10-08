#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define M 202
#define L 10002


int n,m,l;

int fav[M];
int cor[L];

int dp[L][M];

int hash[M];

int max(int a,int b){
	return a>b?a:b;
}

int main(){
	scanf("%d",&n);

	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&fav[i]);
		hash[fav[i]]=i+1;
	}
	scanf("%d",&l);
	for(int i=0;i<l;i++){
		scanf("%d",&cor[i]);
	}

	memset(dp,0,sizeof(int)*M*L);
	if(hash[cor[0]]){
		for(int i=1;i<hash[cor[0]];i++)
			dp[0][i]=0;
		for(int i=hash[cor[0]];i<=m;i++)
			dp[0][i]=1;
	}

	for(int i=0;i<l;i++){
		dp[i][1]=0;
		for(int j=0;j<=i;j++)
			if(cor[j]==fav[0])
				dp[i][1]++;
	}

	for(int i=1;i<l;i++){		
		for(int j=2;j<=m;j++)
			if(hash[cor[i]]<=j&&hash[cor[i]]){
				dp[i][j]=max(1 + dp[i-1][hash[cor[i]]], dp[i-1][j]);
			}else{
				dp[i][j]=dp[i-1][j];
			}
	}

	printf("%d\n", dp[l-1][m]);
	







	return 0;
}

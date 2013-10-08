#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <string.h>
#define N 100005
int dis[N];
int n,sum,m;
int main(){

	scanf("%d",&n);
	sum = 0;
	dis[0]=0;
	for(int i = 1;i<=n;i++){
		scanf("%d",&dis[i]);
		sum += dis[i];
		dis[i]+=dis[i-1];
	}





	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		a--;
		b--;
		int min = a>b?b:a;
		int max= a>b?a:b;
		int t = dis[max]-dis[min];
		if(t>sum/2)
			t =sum-t;
		printf("%d\n",t);

	}

	return 0;
}



/*
Sample Input:
5 1 2 4 14 9
3
1 3
2 5
4 1
Sample Output:
3
10
7
*/
#include <stdio.h>
#include <cstdlib>
#include <math.h>

#define N 36

int n,base;
int out[N];
int len;
int main()
{
	scanf("%d%d",&n,&base);
//n == 0 ?
	if(n == 0){
		printf("Yes\n0\n");
		return 0;
	}
	len = 0;
	while(n!=0){
		out[len++] = n%base;
		n /= base;
	}

	int flag = 1;
	for(int i=0;i<len/2;i++)
		if(out[i]!=out[len-1-i]){
			flag = 0;
			break;
		}
	if(flag == 1)
		printf("Yes\n");
	else
		printf("No\n");

	printf("%d",out[len-1]);

	for(int i = len-2;i>=0;i--)
		printf(" %d",out[i]);



	system("pause");
	return 0;
}


/*
Sample Input 1:
27 2
Sample Output 1:
Yes
1 1 0 1 1
Sample Input 2:
121 5
Sample Output 2:
No
4 4 1
*/
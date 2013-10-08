#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <string.h>

char str[82];
int len;
int n1,n2;
int main()
{
	scanf("%s",str);
	len = strlen(str);
	n1 = (len+2)/3;
	while(n1){
		n2=len+2-2*n1;
		if(n2>=3&&n2>=n1&&n2<=len)
			break;
		n1--;
	}
	//printf("n1:%d n2:%d",n1,n2);
	for(int i=0;i<n1-1;i++){
		printf("%c",str[i]);
		for(int i=0;i<n2-2;i++)
			printf(" ");
		printf("%c\n",str[len-1-i]);
	}
	for(int i=0;i<n2;i++)
		printf("%c",str[n1-1+i]);
	printf("\n");


	//system("pause");
	return 0;
}


/*
Sample Input:
helloworld!
Sample Output:
h   !
e   d
l   l
lowor
*/
#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <string.h>

#define N 1002

char str[N];
int c;
int d;
int max;
int main()
{
	//printf("%d",strlen(test));
	//scanf("%[^\n]",str);
	gets(str);
	//printf("%d",strlen(str));
	c=1;
	d=0;
	max = 1;
	for(int i=1;i< strlen(str);i++){
		c=1;
		for(int j=i-1,k=i+1;(j>=0)&&(k<strlen(str));j--,k++)
			if(str[j]==str[k])
				c+=2;
			else
				break;
		if(max < c)
			max = c;
		d=0;
		for(int j=i-1,k=i;(j>=0)&&(k<strlen(str));j--,k++)
			if(str[j]==str[k])
				d+=2;
			else
				break;
		if(max < d)
			max = d;
	}

	//for(int i=0;i<strlen(str);i++)
	//	printf("%d:%d\n",i,c[i]);
	printf("%d\n",max);
	system("pause");
	return 0;
}


/*
Sample Input:
Is PAT&TAP symmetric?
Sample Output:
11
*/
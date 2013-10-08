#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <string.h>


int r,g,b;
char out[6];
char fun(int t){
	if(t<10)
		return ('0'+t);
	else 
		return ('A'+t-10);
}
int main()
{
	scanf("%d%d%d",&r,&g,&b);
	out[0]=fun(r/13);
	out[1]=fun(r%13);
	out[2]=fun(g/13);
	out[3]=fun(g%13);	
	out[4]=fun(b/13);
	out[5]=fun(b%13);	//t1=r/13;
	printf("#%s\n",out);
	system("pause");
	return 0;
}


/*
Sample Input
15 43 71
Sample Output
#123456
*/
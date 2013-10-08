#include <stdio.h>
#include <cstdlib>
int n;
int sum;
int last;
int main()
{
	scanf("%d",&n);
	last = 0;
	sum = 0;
	for(int i=0; i<n;i++){
		int t;
		scanf("%d",&t);
		if(t>last)
			sum+=(t-last)*6;
		else
			sum += (last-t)*4;
		last = t;
		sum+=5;
	}

	printf("%d\n",sum);
	//system("pause");
	return 0;
}
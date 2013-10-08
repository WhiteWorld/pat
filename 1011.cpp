#include <stdio.h>
#include <cstdlib>
#include <math.h>


float profit;

float max(float a, float b){
	if(a>b)
		return a;
	return b;
}

int main()
{
	profit = 1.0;
	for(int i=0;i<3;i++){
		float a,b,c,maxf;
		scanf("%f%f%f",&a,&b,&c);
		maxf = max(a,max(b,c));
		if(maxf == a){
			printf("W ");
			profit *= a;
		}
		else if(maxf == b){
			printf("T ");
			profit *= b;
		}
		else{
			printf("L ");
			profit *= c;
		}
	}
	printf("%.2f\n",(profit*0.65-1.0)*2);
	system("pause");
	return 0;
}


/*
Sample Input
1.1 2.5 1.7
1.2 3.0 1.6
4.1 1.2 1.1
Sample Output
T T W 37.98
*/
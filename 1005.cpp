#include <stdio.h>
#include <string.h>
#define N 102

char a[N];
char tab[10][10]={
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine"
};

int sum;
int main(){

	scanf("%s",a);
	sum = 0;
	for(int i=0;i<strlen(a);i++)
		sum+=(a[i]-'0');
	if(sum < 10){
		printf("%s\n", tab[sum]);
	}else if(sum < 100){
		printf("%s %s",tab[sum/10],tab[sum%10] );
	}else{
		printf("%s %s %s\n", tab[sum/100],tab[sum%100/10],tab[sum%10]);
	}


	return 0;
}
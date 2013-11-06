#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <iostream>
using namespace std;

void num2str(int n,int *p){
	p[0]=n/1000;
	p[1]=n%1000/100;
	p[2]=n%100/10;
	p[3]=n%10;
}
int str2num(int *p){
	return p[0]*1000+p[1]*100+p[2]*10+p[3];
}
bool cmp1(int a, int b){
	return a<b;
}
bool cmp2(int a, int b){
	return a>b;
}
int main(){
	int n;
	scanf("%d",&n);
	while(1){
		int tab[4];
		int min,max;
		num2str(n,tab);
		sort(tab,tab+4,cmp1);
		min=str2num(tab);
		sort(tab,tab+4,cmp2);
		max=str2num(tab);
		n=max-min;
		printf("%04d - %04d = %04d\n",max,min,n);
		if(n==0||n==6174)
			break;
	}

	system("PAUSE");
	return 0;
}

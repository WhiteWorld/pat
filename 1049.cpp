#include<iostream>
#include<string.h>
#include<sstream>
#include<vector>
#include <cmath>
#include<algorithm>
using namespace std;

char a[20];
int len;
int str2num(int k){

	int t=1;
	int sum=0;
	for(int i=len-1;i>=k;i--){
		sum+=(a[i]-'0')*t;
		t*=10;
	}
	return sum;
}
int fun(int k){
	//printf("k:%d\n",k);
	if(k==len-1){
		if(a[k]=='0')
			return 0;
		else 
			return 1;
	}else{
		if(a[k]=='0')
			return fun(k+1);
		if(a[k]=='1')
			return int(pow(10.0,len-1-k-1)*(len-1-k)*(a[k]-'0'))+fun(k+1)+str2num(k+1)+1;
		return int(pow(10.0,len-1-k-1)*(len-1-k)*(a[k]-'0'))+fun(k+1)+pow(10.0,len-1-k);
	}
}

int main(){
	scanf("%s",a);

	len = strlen(a);
	//printf("%d\n",str2num(0));

	printf("%d\n",fun(0));
    system("pause");
    return 0;
}

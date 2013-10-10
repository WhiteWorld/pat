#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
int d;
int reversible(int n){

	// int b[100000];
	// int i=0;
	// int res=0;
	// while(n!=0){
	// 	b[i++]=(n%10);
	// 	n/=10;
	// }
	// int t=1;
	// for(int j=i-1;j>=0;j--){
	// 	res+=b[j]*t;
	// 	t*=10;
	// }
	// return res;

    int a[100000];  
    memset(a,0,sizeof(a));  
    int total = 0;  
    int j;  
    int i;  
    for(i=0; ; i++){  
        a[i] = n%d;  
        n /= d;  
        if(n==0) break;  
    }  
  
    for(j=0; j<=i; j++)  
    {  
        total = total*d + a[j];  
    }  
    return total;

}
bool prime(int a){
	// if(a<2)
	// 	return false;
	// for(int i=2;i<=sqrt(a);i++)
	// 	if(a%i==0)
	// 		return false;
	// return true;

	int i;  
    if(a==0 || a==1) return false;  
  
    //注意是i<=sqrt(),之前弄成i<sqrt,一直出错  
    for(i=2; i <= sqrt((double)a); i++){  
        if( a%i == 0) return false;  
    }  
  
    return true;  
}
int main(){
	int n;
    int ac;
	while(1){
		scanf("%d",&n);
		if(n<0)
			break;
		scanf("%d",&d);
		ac=0;
		int t=1;
		int origin;
		origin=n;
		while(n!=0){
			ac+=(n%10)*t;
			t*=d;
			n/=10;
		}
		//printf("a:%d\nra:%d\n",a,reversible(a));
		if(prime(origin)&&prime(reversible(origin)))
			printf("Yes\n");
		else
			printf("No\n");



	}
	return 0;
}

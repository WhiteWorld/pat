#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1004;
typedef struct {
	double n;
	double price;
}Cake;
Cake cake[N];

bool cmp(Cake a,Cake b){
	return a.price*b.n > a.n*b.price;
}

int main(){
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=0;i<n;i++)
		scanf("%lf",&cake[i].n);
	for(int i=0;i<n;i++)
		scanf("%lf",&cake[i].price);
	sort(cake,cake+n,cmp);
	double total=0;
	double profit=0;
	for(int i=0;i<n;i++){
		total+=cake[i].n;
		if(total>=d){
			total-=cake[i].n;
			profit+=(d-total)*cake[i].price/double(cake[i].n);
			break;
		}else{
			profit+=cake[i].price;
		}
	}
	printf("%.2lf\n",profit);
	
	system("PAUSE");
	return 0;
}

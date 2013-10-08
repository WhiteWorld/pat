#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
/*
贪心策略：假设现在自己处于A站，要考虑的是A站要不要加油，加多少油的问题。找到下一个要加油的站B（距离A站cmax*davg范围内的最便宜的站）。

1. A站油价比B价高，现在油箱里还有油，能跑到B站，那就不加油，直接跑去（这里B站跟2，3情况不同，是距离A站currGas*davg范围内的最便宜的站）

2. A站油价比B价高，现在油箱没油，跑不到B站，为了减少花销，尽量少加油，只加能跑到B站的油。

3. A站油价比B价低，则不管油箱有没有油，跑不跑得到B站，尽量加满油。
*/
#define N 505
int cmax,d,davg,n;


struct station {
	double price;
	double dist;
}s[N];

bool cmp(struct station s1,struct station s2){
	return s1.dist < s2.dist;
}



int main(){
	scanf("%d%d%d%d",&cmax,&d,&davg,&n);

	for(int i=0;i<n;i++){
		scanf("%lf%lf",&s[i].price,&s[i].dist);
	}
	s[n].price = 0;
	s[n].dist = d;

	sort(s,s+n+1,cmp);

	if(s[0].dist > 0){
		printf("The maximum travel distance = 0.00\n");  
        return 0; 
	}else{
		for(int i=0;i<n;){
			
		}


	}


	return 0;
}

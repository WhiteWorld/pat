#include <stdio.h>
#define N 501
//#define MAX 
//assert l >= 0

int city_num,road_num,begin,end;

int teams[N];

int road[N][N];

int main(){

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			road[i][j] = -1;

	scanf("%d%d%d%d",&city_num,&road_num,&begin,&end);
	for(int i=0;i<city_num;i++)
		scanf("%d",&teams[i]);
	for (int i = 0; i < road_num; ++i)
	{
		int c1,c2,l;
		scanf("%d%d%d",&c1,&c2,&l);
		road[c1][c2] = l;
		road[c2][c1] = l;
	}
	for(int k=0;k<city_num;k++)
		for(int i=0;i<city_num;i++)
			for(int j=0;j<city_num;j++)
				if(road[i][j]>0)
					if(road[i][k]+road[k][j]<road[i][j])
						road[i][j] = road[i][k] + road[k][j];
	

	return 0;
}

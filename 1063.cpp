#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define N 1000000001
#define M 10001


bool a[N];
int sets[51][M];
int n,k;

float similarity(int p,int q){
	int nc,nt;
	for(int i=1;i<=sets[q][0];i++)
		a[sets[q][i]]=0;
	for(int i=1;i<=sets[p][0];i++)
		a[sets[p][i]]=0;
	//memset(a,0,sizeof(bool)*N);
	nc=0;
	nt=0;
	for(int i=1;i<=sets[p][0];i++){
		if(sets[p][i]<0)
			continue;
		if(a[sets[p][i]]==0){
			a[sets[p][i]]=1;
			nt++;
			//printf("nt:%d sets:%d\n",nt,sets[p][i]);
		}
	}

	for(int i=1;i<=sets[q][0];i++){
		if(sets[q][i]<0)
			continue;
		if(a[sets[q][i]]==0){
			nt++;
			//printf("nt:%d sets:%d\n",nt,sets[q][i]);
		}else if(a[sets[q][i]]==1){
			nc++;
			//printf("nc:%d sets:%d\n",nc,sets[q][i]);
		}
	}

	//printf("nc:%d nt:%d\n",nc,nt );
	return (float)nc/nt*100.0;
}


int main(){
	scanf("%d",&n);

	for(int i=1;i<=n;i++){
		scanf("%d",&sets[i][0]);
		//memset(a,0,sizeof(bool)*N);
		for(int j=1;j<=sets[i][0];j++){
			int t;
			scanf("%d",&t);
			if(a[t]==0){
				a[t]=1;
				sets[i][j]=t;
			}else{
				sets[i][j]=-1;
			}
		}
		for(int j=1;j<=sets[i][0];j++)
			if(sets[i][j]>=0)
				a[sets[i][j]]=0;
	}
	scanf("%d",&k);
	int p,q;
	float result;
	for (int i = 0; i < k; ++i)
	{
		scanf("%d%d",&p,&q);
		result = similarity(p,q);
		printf("%.1f%\n",result);
	}



	return 0;
}

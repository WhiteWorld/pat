#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1024;
const int INF=0x7fffff;
int n,m,k,ds;
int dist[N][N];
int road[N][N];
int mindis[22];
int total[22];
int str2num(char *str){
	if(str[0]=='G'){
		return n+str2num(str+1);
	}else{
		int total=0;
		int t=1;
		for(int i=strlen(str)-1;i>=0;i--){
			total+=t*(str[i]-'0');
			t*=10;
		}
		return total;
	}
}
int main(){

	scanf("%d%d%d%d",&n,&m,&k,&ds);

	for(int i=1;i<=n+m;i++)
		for(int j=1;j<=n+m;j++)
			if(i==j)
				dist[i][j]=0;
			else
				dist[i][j]=INF;

	for(int i=0;i<k;i++){
		char a[5];
		char b[5];
		int c;
		scanf("%s%s%d",a,b,&c);
		int an,bn;
		an=str2num(a);
		bn=str2num(b);
		//cout<<"an:"<<an<<"bn:"<<bn<<endl;
		dist[an][bn]=c;
		dist[bn][an]=c;
	}
	for(int k=1;k<=n+m;k++)
		for(int i=1;i<=n+m;i++)
			for(int j=1;j<=n+m;j++)
				if(dist[i][k]!=INF&&dist[k][j]!=INF&&(dist[i][k]+dist[k][j]<dist[i][j]))
					dist[i][j]=dist[i][k]+dist[k][j];

	int Min,Max;
	Min=INF;
	Max=-1;
	int cnt=-1;
	for(int i=1;i<=m;i++){
		mindis[i]=INF;
		total[i]=0;
		for(int j=1;j<=n;j++)
			if(dist[i][j]>ds){
				mindis[i]=-1;
				break;
			}else if(dist[i][j]<mindis[i]){
				mindis[i]=dist[i][j];
				total[i]+=dist[i][j];
			}
		if(mindis[i]!=-1)
			if(total[i]>Max){
				Max=total[i];
				cnt=i;
			}
	}
	if(cnt==-1)
		printf("No Solution\n");
	else
		printf("%d\n%.1f %.1f\n",cnt,mindis[cnt],Max/float(n));

	system("PAUSE");
	return 0;
}

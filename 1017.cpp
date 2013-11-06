#include <stdio.h>
#include <algorithm>
#define N 10005
#define K 103
#define START 8*3600
#define END 17*3600
#define INF 0x7fffffff
typedef struct 
{
	int time;
	int process;
	int serve;
	int leave;
}People;

People people[N];
int now[K];

bool cmp(People a,People b){
	return a.time < b.time;
}
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	int n,k;
	int h,m,s,t;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d:%d:%d %d",&h,&m,&s,&t);
		people[i].time=h*3600+m*60+s;
		people[i].process=t*60;
	}
	std::sort(people,people+n,cmp);
	for(int i=0;i<k;i++)
		now[i]=START;
	for(int i=0;i<n;i++){
		int min=INF;
		int index;
		for(int j=0;j<k;j++){
			if(now[j]<min){
				min=now[j];
				index=j;
			}
		}
		people[i].serve=max(people[i].time,now[index]);
		people[i].leave=people[i].serve+people[i].process;
		now[index]=people[i].leave;
	}
	int total=0;
	int cnt=0;
	for(int i=0;i<n;i++){
		if(people[i].time<=END){
			cnt++;
			total+= (people[i].serve - people[i].time);
		}
	}

	printf("%.1f\n",float(total)/cnt/60.0);



	return 0;
}

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=10004;
const int INF=0x7fffffff;
int n,k,m;

typedef struct {
	int h,m,s;
	int process;
	int atime;
	int stime;
	int vip;
	int playered;
}Player;

Player player[N];
int vip[102];
int time[102];
bool cmp(Player a,Player b){
	return a.atime < b.atime;
}
bool cmp1(Player a,Player b){
	return a.stime < b.stime;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d:%d:%d %d %d",&player[i].h,&player[i].m,&player[i].s,&player[i].process,&player[i].vip);
		player[i].atime=player[i].h*3600+player[i].m*60+player[i].s;
	}
	cin>>k>>m;
	for(int i=0;i<m;i++){
		int t;
		cin>>t;
		vip[t]=1;
	}

	for(int i=0;i<k;i++)
		time[i]=8*3600;

	sort(player,player+n,cmp);
	for(int i=0;i<n;i++){
		if(player[i].playered){
			int min=INF;
			int index;
			for(int j=0;j<k;j++){
				if(time[j]<min){
					min=time[j];
					index=j;
				}
			}
			if(min>player[i].atime)//满了
			{
				if(vip[index])//空出来的是vip
				{
					int t=-1;
					for(int j=i;j<n;j++)
						if(player[j].vip&&!player[j].playered&&player[j].atime<min){
							player[j].playered=1;
							player[j].stime=min;
							time[index]=player[j].process+min;
							t=j;
						}
					if(t==-1)//没找到符合条件的vip
					{
							player[i].playered=1;
							player[i].stime=min;
							time[index]=player[i].process+min;
					}
				}else{//普通位子
							player[i].playered=1;
							player[i].stime=min;
							time[index]=player[i].process+min;
				}
			}else{//有空位
				//vip table
				int vips=0;
				for(int j=0;j<k;j++)
					if(time[j]<=player[i].atime&&vip[j])
						vips++;
				if(vips==0)//no vip tables
				{
					int t;
					for(t=0;t<k;t++)
						if(time[t]<=player[i].atime)
							break;
					player[i].playered=1;
					player[i].stime=player[i].atime;
					time[t]=player[i].process+player[i].atime;
				}else{//vip tables
					if(player[i].vip)//is vip
					{
						int t;
						for(t=0;t<k;t++)
							if(time[t]<=player[i].atime&&vip[t])
								break;
						player[i].playered=1;
						player[i].stime=player[i].atime;
						//player[i].wtime=0;
						time[t]=player[i].process+player[i].atime;
					}else{// is not vip
						int t;
						for(t=0;t<k;t++)
							if(time[t]<=player[i].atime)
								break;
						player[i].playered=1;
						player[i].stime=player[i].atime;
						time[t]=player[i].process+player[i].atime;
					}
				}
			}
		}
	}
	sort(player,player+n,cmp1);
	for(int i=0;i<n;i++){
		int h,m,s;
		h=player[i].stime/3600;
		m=player[i].stime%3600/60;
		s=player[i].stime%60;
		int total=0;
		//total=(h-player[i].h)*60+(m-player[i])
		printf("%02d:%02d:%02d %02d:%02d:%02d\n",player[i].h,player[i].m,player[i].s,h,m,s);
	}
	system("PAUSE");
	return 0;
}

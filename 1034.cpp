#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define N 1001
#define M 17576
int str2num(char* str){
	return (str[0]-'A')*676+(str[1]-'A')*26+(str[2]-'A');
}
int n,k;
int w[M];
int parent[M];
int head[M];

int find(int t){
	while(t!=parent[t])
		t=parent[t];
	return t;
}
void merge(int a,int b){
		parent[b]=a;
}

int main(){
	for(int i=0;i<M;i++)
		parent[i]=i;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		char str1[4],str2[4];
		int time;
		scanf("%s%s%d",str1,str2,&time);
		int p1,p2;
		p1=str2num(str1);
		p2=str2num(str2);
		w[p1]+=time;
		w[p2]+=time;
		int f1,f2;
		f1=find(p1);
		f2=find(p2);
		if(f1!=f2)
			merge(f1,f2);
	}
	int num=0;
	for(int i=0;i<M;i++)
		if(w[i]&&find(i)==i){
			int sum=0;
			int cnt=0;
			int max=0;
			int index;
			for(int j=0;j<M;j++)
				if(w[j]&&find(j)==i){
					if(w[j]>max){
						max=w[j];
						index=j;
					}
					sum+=w[j];
					cnt++;
				}
			if(sum/2>k&&cnt>2){
				num++;
				head[index]=cnt;
			}
		}
	printf("%d\n",num);
	for(int i=0;i<M;i++)
		if(head[i]>0){
			int t=i;
			char out[4];
			out[2]=t%26+'A';
			out[1]=t/26%26+'A';
			out[0]=t/676%26+'A';
			out[3]='\0';
			printf("%s %d\n",out,head[i]);
		}
	return 0;
}

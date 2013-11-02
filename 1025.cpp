#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define N 40005

int n,k;

struct info
{
	long long id;
	int sc;
	int lr;//local rank
	int ln;//local num
	int fr;//final rank
};
struct info grade[N];
bool cmp(struct info a,struct info b){
	if(a.sc==b.sc)
		return a.id < b.id;
	return a.sc > b.sc;
}
int main(){
	scanf("%d",&n);

	int begin;
	begin = 0;
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=begin;j<k+begin;j++){
			scanf("%Ld%d",&grade[j].id,&grade[j].sc);
			grade[j].ln=i;
		}
		sort(grade+begin,grade+begin+k,cmp);

		grade[begin].lr=1;
		for(int j=begin+1;j<k+begin;j++)
			if(grade[j].sc == grade[j-1].sc)
				grade[j].lr = grade[j-1].lr;
			else
				grade[j].lr = j+1-begin;

		begin = begin+k;
	}
	sort(grade,grade+begin,cmp);

	grade[0].fr=1;
	for(int i=1;i<begin;i++)
		if(grade[i].sc == grade[i-1].sc)
			grade[i].fr = grade[i-1].fr;
		else
			grade[i].fr = i+1;

	printf("%d\n",begin);
	for(int i=0;i<begin;i++)
		printf("%Ld %d %d %d\n",grade[i].id,grade[i].fr,grade[i].ln,grade[i].lr);

	return 0;
}

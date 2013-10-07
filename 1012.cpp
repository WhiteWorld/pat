#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define N 2002

struct stu
{
	int id;
	int c;
	int m;
	int e;
	int a;

	int ra;
	int rc;
	int rm;
	int re;
	/* data */
};

struct stu grade[N];
int n,m;


bool cmpa(struct stu s1,struct stu s2){
	return s1.a > s2.a;
}
bool cmpc(struct stu s1,struct stu s2){
	return s1.c > s2.c; 
}
bool cmpm(struct stu s1,struct stu s2){
	return s1.m > s2.m; 
}
bool cmpe(struct stu s1,struct stu s2){
	return s1.e > s2.e; 
}
int getmin(int a,int c,int m,int e){
	int p,q;
	p=a<c?a:c;
	q=m<e?m:e;
	return p<q?p:q;
}
int main(){

	scanf("%d%d",&n,&m);

	for (int i = 0; i < n; ++i)
	{
		int id,c,m,e,a;
		scanf("%d%d%d%d",&id,&c,&m,&e);
		grade[i].id=id;
		grade[i].c=c;
		grade[i].m=m;
		grade[i].e=e;
		a=(c+m+e);
		grade[i].a=a;
		/* code */
	}
	sort(grade,grade+n,cmpa);
	grade[0].ra=1;
	for(int i=1;i<n;i++){
		if(grade[i].a==grade[i-1].a)
			grade[i].ra=grade[i-1].ra;
		else
			grade[i].ra = i+1;
	}

	sort(grade,grade+n,cmpc);
	grade[0].rc=1;
	for(int i=1;i<n;i++){
		if(grade[i].c==grade[i-1].c)
			grade[i].rc=grade[i-1].rc;
		else
			grade[i].rc = i+1;
	}

	sort(grade,grade+n,cmpm);
	grade[0].rm=1;
	for(int i=1;i<n;i++){
		if(grade[i].m==grade[i-1].m)
			grade[i].rm=grade[i-1].rm;
		else
			grade[i].rm = i+1;
	}

	sort(grade,grade+n,cmpe);
	grade[0].re=1;
	for(int i=1;i<n;i++){
		if(grade[i].e==grade[i-1].e)
			grade[i].re=grade[i-1].re;
		else
			grade[i].re = i+1;
	}
	while(m--){
		int id;
		scanf("%d",&id);
		//printf("%d\n",id );
		int flag=0;
		for(int i=0;i<n;i++)
			if(grade[i].id==id){
				//printf("ID:%d %d %d %d %d\n",grade[i].id, grade[i].ra,grade[i].rc,grade[i].rm,grade[i].re);
				int min;
				min=getmin(grade[i].ra,grade[i].rc,grade[i].rm,grade[i].re);
				if(min==grade[i].ra)
					printf("%d A\n", grade[i].ra);
				else if(min==grade[i].rc)
					printf("%d C\n", grade[i].rc);
				else if(min == grade[i].rm)
					printf("%d M\n", grade[i].rm);
				else 
					printf("%d E\n", grade[i].re);
				flag=1;
				break;
			}
			if(flag==0)
				printf("N/A\n");

		}
		return 0;
	}

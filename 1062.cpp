#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

#define N 100002

struct info
{
	int id;
	int vgrade;
	int tgrade;
	int sum;
	/* data */
};
struct info pinfo[N];

int n,l,h,m;

bool is_sages(struct info a){
	if(a.vgrade>=h&&a.tgrade>=h)
		return true;
	return false;
}
bool is_noblemen(struct info a){
	if(a.vgrade>=h&&a.tgrade<h)
		return true;
	return false;
}
bool is_foolmen(struct info a){
	if(a.vgrade<h&&a.tgrade<h&&a.vgrade>=a.tgrade)
		return true;
	return false;
}

bool compare(struct info a,struct info b){
	if(is_sages(a)&&is_sages(b)){
		if(a.sum==b.sum)
		{
			if(a.vgrade==b.vgrade)
				return a.id<b.id;
			else
				return a.vgrade > b.vgrade;
		}else
		return a.sum > b.sum;
	}else if(is_sages(a)||is_sages(b)){
		if(is_sages(a))
			return true;
		else
			return false;
	}else if(is_noblemen(a)&&is_noblemen(b)){
		if(a.sum==b.sum)
		{
			if(a.vgrade==b.vgrade)
				return a.id<b.id;
			else
				return a.vgrade > b.vgrade;
		}else
		return a.sum > b.sum;
	}else if(is_noblemen(a)||is_noblemen(b)){
		if(is_noblemen(a))
			return true;
		else
			return false;
	}else if(is_foolmen(a)&&is_foolmen(b)){
		if(a.sum==b.sum)
		{
			if(a.vgrade==b.vgrade)
				return a.id<b.id;
			else
				return a.vgrade > b.vgrade;
		}else
		return a.sum > b.sum;
	}else if(is_foolmen(a)||is_foolmen(b)){
		if(is_foolmen(a))
			return true;
		else
			return false;
	}else{
		if(a.sum==b.sum)
		{
			if(a.vgrade==b.vgrade)
				return a.id<b.id;
			else
				return a.vgrade > b.vgrade;
		}else
		return a.sum > b.sum;
	}
}


int main(){
	scanf("%d%d%d",&n,&l,&h);
	m=0;
	for(int i=0;i<n;i++){
		int id,v,t;
		scanf("%d%d%d",&id,&v,&t);
		if(v<l||t<l)
			continue;
		pinfo[m].id=id;
		pinfo[m].vgrade=v;
		pinfo[m].tgrade=t;
		pinfo[m].sum=v+t;
		m++;
	}
	sort(pinfo,pinfo+m,compare);

	printf("%d\n",m);
	for (int i = 0; i < m; ++i)
	{
		printf("%08d %d %d\n",pinfo[i].id,pinfo[i].vgrade,pinfo[i].tgrade);
		/* code */
	}

	return 0;
}
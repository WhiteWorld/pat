#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=100005;
int amin,amax
struct Person{
	char name[9];
	int age;
	int worth;
}per[N];
bool range(int age){
	if(age<=amax&&age>=amin)
		return true;
	else
		return false;
}
bool cmp(struct Person p1, struct Person p2){
	//if(range(p1.age)!=range(p2.age))
	//	return range(p1.age) < range(p2.age);
	//if((p1.age<=amax&&p1.age>=amin)!=(p2.age<=amax&&p2.age>=amin))
	//	return (p1.age<=amax&&p1.age>=amin) >  (p2.age<=amax&&p2.age>=amin);
	//else if(p1.worth!=p2.worth)
	//	return p1.worth > p2.worth;
	//else if(p1.age!=p2.age)
	//	return p1.age < p2.age;
	//else 
	//	return ;
		//return strcmp(p1.name,p2.name) < 0;
	return p1.age < p2.age;
}
int main(){
	int n,k;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%s%d%d",per[i].name,&per[i].age,&per[i].worth);
	for(int i=1;i<=k;i++){
		int m;//[amin,amax]
		scanf("%d%d%d",&m,&amin,&amax);
		printf("Case #%d:\n",i);
		sort(per,per+n,cmp);
		//sort(per,per+n,cmp);
	}

	system("PAUSE");
	return 0;
}

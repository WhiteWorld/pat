#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int n;

struct Num
{
	char s[10];
	/* data */
}num[10002];
bool cmp(struct Num n1,struct Num n2){
	int i=0;
	while(n1.s[i]==n2.s[i]&&i<strlen(n1.s)&&i<strlen(n2.s))
		i++;
	if(i<strlen(n1.s)&&i<strlen(n2.s))
		return n1.s[i]<n2.s[i];
	else if(i==strlen(n1.s)){
		return n1.s[0] <= n2.s[i];
	}else{
		return n1.s[i] < n2.s[0];
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",num[i].s);
	}
	sort(num,num+n,cmp);

	char out[80001];
	int cnt=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<strlen(num[i].s);j++)
			out[cnt++]=num[i].s[j];
	int index=-1;
	for(int i=0;i<cnt;i++)
		if(out[i]!='0'){
			index=i;
			break;
		}
	if(index==-1)
		printf("0\n");
	else{
		printf("%s\n",out+index);
	}

	return 0;
}
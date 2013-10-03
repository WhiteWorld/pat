#include <stdio.h>
#include <string.h>
#define N 105
int n;
char a[N],b[N],oa[N],ob[N];
int pa,pb;
int za,zb;
int ma,mb;
int main(){

	scanf("%d%s%s",&n,a,b);

	pa=strlen(a);
	for(int i=0;i<strlen(a);i++)
		if(a[i]=='.')
		{
			pa=i;
			break;
		}
	a[pa]='.';

	int sa;
	for (sa = 0; sa < strlen(a); sa++)
		if(a[sa]!='0'&&a[sa]!='.')
			break;
	if(sa==strlen(a)){
		//0.00
		oa[0]='0';
		oa[1]='.';
		for(int i=0;i<n;i++)
			oa[i+2]='0';
		ma=0;
	}else{
		oa[0]='0';
		oa[1]='.';
		for(int i=0,j=sa;i<n;j++)
			if(j<strlen(a)){
				if(j==pa)
					continue;
				else{
					oa[i+2]=a[j];
					i++;
				}
			}else{
				oa[i+2]='0';
				i++;
			}
		ma = pa-sa;
		if(ma<0)
			ma++;
	}
// printf("YES %s*10^%d\n",oa,ma);
// return 0;
		pb=strlen(b);
	for(int i=0;i<strlen(b);i++)
		if(b[i]=='.')
		{
			pb=i;
			break;
		}
	b[pb]='.';

	int sb;
	for (sb = 0; sb < strlen(b); sb++)
		if(b[sb]!='0'&&b[sb]!='.')
			break;
	if(sb==strlen(b)){
		//0.00
		ob[0]='0';
		ob[1]='.';
		for(int i=0;i<n;i++)
			ob[i+2]='0';
		mb=0;
	}else{
		ob[0]='0';
		ob[1]='.';
		for(int i=0,j=sb;i<n;j++)
			if(j<strlen(b)){
				if(j==pb)
					continue;
				else{
					ob[i+2]=b[j];
					i++;
				}
			}else{
				ob[i+2]='0';
				i++;
			}
		mb = pb-sb;
		if(mb<0)
			mb++;
	}

	int equal=1;
	if(ma!=mb)
		equal=0;
	for(int i=0;i<n+2;i++)
		if(oa[i]!=ob[i])
		{
			equal=0;
			break;
		}

	if(equal)
		printf("YES %s*10^%d\n",oa,ma);
	else
		printf("NO %s*10^%d %s*10^%d\n",oa,ma,ob,mb);

	return 0;
	
}
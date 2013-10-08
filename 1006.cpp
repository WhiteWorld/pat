#include <stdio.h>
#include <cstdlib>
#define N 17
#define M 9
int n;
char signin[N],signout[N],s[N];
char t[M];
int intt;
int begin=0,end=0;

int main()
{
	scanf("%d",&n);

	scanf("%s",signin);
	for(int i=0;i<N;i++)
		signout[i] = signin[i];

	scanf("%s",t);
	for(int i=0;i<M;i++)
		t[i] = t[i] - '0';
	begin = ((t[0]*10+t[1])*3600+(t[3]*10+t[4])*60+(t[6]*10+t[7]));


	scanf("%s",t);
	for(int i=0;i<M;i++)
		t[i] = t[i] - '0';
	end = ((t[0]*10+t[1])*3600+(t[3]*10+t[4])*60+(t[6]*10+t[7]));


	for(int i = 1;i < n; i++){
		scanf("%s", s);
		
		scanf("%s",t);
		for(int i=0;i<M;i++)
			t[i] = t[i] - '0';
		intt = ((t[0]*10+t[1])*3600+(t[3]*10+t[4])*60+(t[6]*10+t[7]));
		if(intt < begin){
			begin = intt;
			for(int i=0;i<N;i++)
				signin[i] = s[i];
		}
		scanf("%s",t);

		for(int i=0;i<M;i++)
			t[i] = t[i] - '0';
		intt = ((t[0]*10+t[1])*3600+(t[3]*10+t[4])*60+(t[6]*10+t[7]));
		if(intt > end){
			end = intt;
			for(int i=0;i<N;i++)
				signout[i] = s[i];
		}
	}

	printf("%s %s\n",signin,signout);
	//system("pause");
	return 0;
}
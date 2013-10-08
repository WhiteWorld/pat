#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <string.h>

#define N 120

char nc[N];
int k;

bool palindromic(char nc[], int len){
	for(int i=0;i<len/2;i++)
		if(nc[i]!=nc[len-1-i])
			return false;
	return true;
}


int main()
{
	scanf("%s%d",nc,&k);
	int len = strlen(nc);

	for(int i=0;i<k;i++){
		if(palindromic(nc,len)){
			printf("%s\n%d\n",nc,i);
			//system("pause");
			return 0;
		}
		char t[N];
		for(int i=0; i< N;i++)
			t[i]='0';

		//printf("%s\n",nc);
		for(int i = 0;i<len;i++){
			t[i] += (nc[i]-'0'+nc[len-1-i]-'0');
			t[i+1] += (t[i]-'0')/10;
			t[i] = '0'+(t[i]-'0')%10;
		}
		
		//if(t[len]=='0')
		//	t[len] = '\0';
		//else
		//	t[len+1] = '\0';
		//printf("t:%s\n",t);

		for(int i=N-1;i>=0;i--){
			if(t[i]!='0'){
				len=i+1;
				break;
			}
		}
		for(int i=len-1;i>=0;i--)
			nc[len-1-i] = t[i];
		nc[len]='\0';

		//printf("nc:%s len: %d\n",nc,len);
	}


	printf("%s\n%d\n",nc,k);

	//system("pause");
	return 0;
}


/*
Sample Input 1:
67 3
Sample Output 1:
484
2
Sample Input 2:
69 3
Sample Output 2:
1353
3
*/
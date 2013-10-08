#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <string.h>

char account[1002][2][12];
int check[1002];
int n;
bool change(char *c){
	if(*c == '1'){
		*c='@';
		return true;
	}
	if(*c == '0'){
		*c='%';
		return true;
	}
	if(*c == 'l'){
		*c='L';
		return true;
	}
	if(*c == 'O'){
		*c='o';
		return true;
	}
	return false;
}

int main()
{
	
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		check[i]=0;
		scanf("%s%s",account[i][0],account[i][1]);
		for(int j=0;j<strlen(account[i][1]);j++)
			if(change(&account[i][1][j]))
				check[i] = 1;
	}
	int count = 0;
	for(int i=0;i<1002;i++)
		if(check[i]==1)
			count++;
	if(count==0){
		if(n!=1)
			printf("There are %d accounts and no account is modified\n",n);
		else
			printf("There is 1 account and no account is modified\n");
	}else{
		printf("%d\n",count);
		for(int i=0;i<n;i++)
			if(check[i]==1)
				printf("%s %s\n",account[i][0],account[i][1]);
	}

	//system("pause");
	return 0;
}


/*
Sample Input 1:

3
Team000002 Rlsp0dfa
Team000003 perfectpwd
Team000001 R1spOdfa
Sample Output 1:
2
Team000002 RLsp%dfa
Team000001 R@spodfa
Sample Input 2:
1
team110 abcdefg332
Sample Output 2:
There is 1 account and no account is modified
Sample Input 3:
2
team110 abcdefg222
team220 abcdefg333
Sample Output 3:
There are 2 accounts and no account is modified

*/
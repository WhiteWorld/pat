#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

char a[22];
int b[22];
int c[10];
int d[10];
int main(){
	scanf("%s",a);
	for(int i=0;i<strlen(a);i++){
		c[a[i]-'0']++;
		b[i]=(a[i]-'0')*2;
	}
	for(int i=strlen(a)-1;i>=1;i--)
		if(b[i]>9){
			b[i-1]+=b[i]/10;
			b[i]=b[i]%10;
		}
	//b[0]=b[0]%10;
	if(b[0]>9){
		printf("No\n");
		for(int i=0;i<strlen(a);i++)
			printf("%d",b[i]);
	}else{

		for(int i=0;i<strlen(a);i++)
			d[b[i]]++;
		int index=-1;
		for(int i=0;i<10;i++)
			if(c[i]!=d[i]){
				index=i;
				break;
			}
		if(index!=-1){
			printf("No\n");
		}else{
			printf("Yes\n");
		}
		for(int i=0;i<strlen(a);i++)
			printf("%d",b[i]);
	}




	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int k;
int order[55];

int out[55];

int find(int index,int times){
	if(times<=0)
		return 0 ;
	int t;
	t=index;
	while(times--){
		t=order[t];
	}
	return t;
}

void print(int i){
	if(i<=13){
		printf("S%d",i);
	}else if(i<=26){
		printf("H%d",i-13);
	}else if(i<=39){
		printf("C%d",i-26);
	}else if(i<=52)
		printf("D%d", i-39);
	else
		printf("J%d", i-52);
}

int main(){
	scanf("%d", &k);
	for(int i=1;i<=54;i++)
		scanf("%d",&order[i]);

	for(int i=1;i<55;i++)
		out[find(i,k)]=i;

	print(out[1]);
	for(int i=2;i<55;i++){
		printf(" ");
		print(out[i]);
	}
	printf("\n");
	return 0;
}

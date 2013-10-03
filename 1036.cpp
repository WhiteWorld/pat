#include <stdio.h>
int n;
char minm[2][12];
char maxf[2][12];
int min,max;
int main(){
	scanf("%d",&n);
	min = 101;
	max = -1;
	for(int i=0;i<n;i++){
		char name[12];
		char gender;
		char id[12];
		int grade;
		scanf("%s %c %s %d",name,&gender,id,&grade);
		//printf("%s:%c:%s:%d\n",name,gender,id,grade);//d
		//continue;//d

		if(gender=='M'){
			if(grade < min){
				min = grade;
				for(int i=0;i<12;i++)
					minm[0][i]=name[i];
				for(int i=0;i<12;i++)
					minm[1][i]=id[i];
			}
		}else{
			if(grade > max){
				max = grade;
				for(int i=0;i<12;i++)
					maxf[0][i]=name[i];
				for(int i=0;i<12;i++)
					maxf[1][i]=id[i];
			}		
		}
	}
	//return 0;//d
	if(max==-1)
		printf("Absent\n");
	else
		printf("%s %s\n",maxf[0],maxf[1]);

	if(min==101){
		printf("Absent\n");
	}else{
		printf("%s %s\n",minm[0],minm[1]);
	}

	if((max == -1)||(min == 101))
		printf("NA\n");
	else
		printf("%d\n",max-min);
	return 0;
}
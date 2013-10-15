#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


const int K = 2501;



int str2num(char*str){
	return (str[0]-'A')*26*26*10+(str[1]-'A')*26*10+(str[2]-'A')*10+(str[3]-'0');
}
void num2str(int num,char *str){
	str[0] = num/10/26/26%26 +'A';
	str[1] = num/10/26%26 + 'A';
	str[2] = num/10%26 + 'A';
	str[3] = num%10 + '0';
	str[4] = '\0';
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	vector<vector<int>> course(K);
	for(int i=0;i<n;i++){
		char sid[5];
		int num;
		scanf("%s %d",&sid,&num);
		for(int j=0;j<num;j++){
			int t;
			scanf("%d",&t);
			course[t].push_back(str2num(sid));
		}
	}
	for(int i=1;i<=k;i++){
		char name[5];
		vector<int>::iterator iter_vec;
		printf("%d %d\n",i,course[i].size());
		sort(course[i].begin(),course[i].end());
		
		for(iter_vec=course[i].begin();iter_vec!=course[i].end();iter_vec++){
				num2str(*iter_vec,name);
				printf("%s\n",name);
		}
	}
	system("PAUSE");
	return 0;
}

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//const int N = 40004;
const int K = 2501;
const int M = 26*26*26*10;
//bool hash[M][K];

int str2num(char*str){
	return (str[0]-'A')*26*26*10+(str[1]-'A')*26*10+(str[2]-'A')*10+(str[3]-'0');
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	vector<vector<int>> stu(M+1);
	for(int i=0;i<k;i++){
		int cid,num;
		scanf("%d%d",&cid,&num);
		for(int j=0;j<num;j++){
			char tstr[5];
			scanf("%s",tstr);
			//hash[str2num(tstr)][cid]=1;
			stu[str2num(tstr)].push_back(cid);
		}
	}
	for(int i=0;i<n;i++){
		char tstr[5];
		scanf("%s",tstr);
		//printf("%s ",tstr);
		int cnt=0;
		int tnum=str2num(tstr);
		vector<int>::iterator iter_vec;
		//for(iter_vec=stu[str2num(tstr)].begin();iter_vec!=stu[str2num(tstr)].end();iter_vec++)
		//	if(stu[str2num(tstr)].size()!=0)
		//		cnt++;
		printf("%s %d",tstr,stu[str2num(tstr)].size());
		sort(stu[str2num(tstr)].begin(),stu[str2num(tstr)].end());
		
		for(iter_vec=stu[str2num(tstr)].begin();iter_vec!=stu[str2num(tstr)].end();iter_vec++)
				printf(" %d",*iter_vec);
		printf("\n");
	}
	system("PAUSE");
	return 0;
}

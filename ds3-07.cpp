#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <iostream>
using namespace std;
typedef struct {
	double num;
	char type;//'0':int,1:'+',2:'-',3:'*',4:'/'
	//char ch;
}Node;
Node mynode[32];

double str2num(char *str){
	double d;
	int positive=1;
	int start=0;
	if(str[0]=='+'){
		positive=1;
		start=1;
	}else if(str[0]=='-'){
		positive=-1;
		start=1;
	}
	//处理小数点。。。
	int point=-1;
	for(int i=start;i<strlen(str);i++)
		if(str[i]=='.')
			point=i;
	d=0;
	if(point==-1){//整数
		for(int i=strlen(str)-1;i>=start;i--)
			d+=(str[i]-'0')*pow(10.0,double(strlen(str)-1-i));
	}else{//小数
		for(int i=point-1;i>=start;i--)
			d+=(str[i]-'0')*pow(10.0,double(point-1-i));
		for(int i=point+1;i<strlen(str);i++)
			d+=(str[i]-'0')*pow(10.0,double(point-i));
	}
	d=d*positive;
	return d;
}

int main(){
	char str[40];
	stack<Node>s;

	int myerror=0;
	int index=0;
	while(cin>>str){
		//printf("str:%s\n",str);
		if(strlen(str)==1){
			if(str[0]>='0'&&str[0]<='9'){
				mynode[index].type='0';
				mynode[index].num=str[0]-'0';
				//printf("num %d",mynode[index].num);
			}else{
				mynode[index].type=str[0];
			}
			index++;
		}else if(strlen(str)>1){
			mynode[index].type='0';
			mynode[index].num=str2num(str);
			index++;
			//printf("num %d",mynode[index].num);
		}
		//memset(str,'\0',sizeof(str));
	}
	for(int i=0;i<index;i++){
		if(mynode[i].type=='0'){
			if(s.empty()){
				//myerror=1;
				//break;
				s.push(mynode[i]);
			}else if(s.size()==1){
				if(s.top().type=='0'){
					myerror=1;
					break;
				}else{
					s.push(mynode[i]);
				}
			}else if(s.size()>=2){
				if(s.top().type!='0'){
					s.push(mynode[i]);
				}else{
					Node pnode=s.top();
					s.pop();
					Node tnode=s.top();
					s.pop();
					if(tnode.type=='0'){
						myerror=1;
						break;
					}
					Node rnode;
					rnode.type='0';
					rnode.num=0;
					if(tnode.type=='+'){
						rnode.num=pnode.num+mynode[i].num;
					}else if(tnode.type=='-'){
						rnode.num=pnode.num-mynode[i].num;
					}else if(tnode.type=='*'){
						rnode.num=pnode.num*mynode[i].num;
					}else if(tnode.type=='/'){
						if(fabs(mynode[i].num)<0.000001){
							myerror=1;
							break;
						}else
							rnode.num=pnode.num/mynode[i].num;
					}
					mynode[i].type=rnode.type;
					mynode[i].num=rnode.num;
					i--;
				}
			}
		}else{
			s.push(mynode[i]);
		}
	}
	if(myerror==1||s.size()!=1)
		printf("ERROR\n");
	else
		printf("%.1f\n",s.top().num);


	system("PAUSE");
	return 0;
}

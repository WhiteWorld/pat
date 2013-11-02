#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;


int fuhao(char ch){
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
		return 1;
	else if(ch=='('||ch==')')
		return 2;
	else if(ch>='0'&&ch<='9')
		return 0;
	else 
		return 3;
}
bool cmp(char a, char b){
	if(a=='(')
		return 0;
	if((a=='+'||a=='-')&&(b=='+'||b=='-'))
		return 1;
	else if((a=='+'||a=='-')&&(b=='*'||b=='/'))
		return 0;
	else if((a=='*'||a=='/')&&(b=='*'||b=='/'))
		return 1;
	else 
		return 1;
}
int main(){
	char str[21];
	char out[21];
	int index=0;
	scanf("%s",str);
	stack<int> s;
	int first=1;
	for(int i=0;i<strlen(str);i++)
		if(fuhao(str[i])==0){
			  if(i==1&&str[0]=='-'){
				  if(first){
					  printf("-%c",str[1]);
					  first=0;
				  }
			  }else if(i>1&&str[i-1]=='-'&&str[i-2]=='('){
				  if(first){
					  printf("-%c",str[i]);
					  first=0;
				  }else
					  printf(" -%c",str[i]);
			  }else if(i>0&&fuhao(str[i])==0&&(str[i-1]=='.'||(fuhao(str[i-1])==0))){
				  printf("%c",str[i]);
			  }else{
				  if(first){
					  printf("%c",str[i]);
					  first=0;
				  }else{
					  printf(" %c",str[i]);
				  }
			  }
		}else if(str[i]=='('){
			s.push(str[i]);
		}else if(str[i]==')'){
			while(s.top()!='('){
				printf(" %c",s.top());
				s.pop();
			}
			s.pop();
		}else if(str[i]=='.'){
			printf(".");
		}else if(i>0&&(str[i]=='-'||str[i]=='+')&&str[i-1]=='('){
			continue;
		}else if(i==0&&(str[i]=='-'||str[i]=='+')){
			continue;
		}else if(fuhao(str[i+1])==0||str[i+1]=='('){

			//'-'

			while(!s.empty()){
				if(cmp(s.top(),str[i])){
					printf(" %c",s.top());
					s.pop();
				}else
					break;
			}
			s.push(str[i]);
		}
	while(!s.empty()){
		printf(" %c",s.top());
		s.pop();
	}
	printf("\n");

	system("PAUSE");
	return 0;
}

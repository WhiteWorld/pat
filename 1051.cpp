#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

int a[1001];
int main(){
	int m,n,k;
	scanf("%d%d%d",&m,&n,&k);
	while(k--){
		stack<int> s1,s2;
		while(!s1.empty())
			s1.pop();
		while(!s2.empty())
			s2.pop();
		for(int i=n;i>=1;i--)
			s1.push(i);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		int flag=1;
		for(int i=0;i<n;i++){
			if(!s1.empty()&&a[i]==s1.top()&&s2.size()<m)
				s1.pop();
			else if(!s2.empty()&&a[i]==s2.top())
				s2.pop();
			else if(!s1.empty()&&s2.size()<m){
				int t=s1.top();
				s2.push(t);
				s1.pop();
				i--;
			}else{
				flag=0;
				break;
			}
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	system("PAUSE");
	return 0;
}

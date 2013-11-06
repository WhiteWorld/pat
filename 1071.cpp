#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){

	string s;
	map <string, int> m;
	while(cin>>s){
		string t;
		int index=0;
		t.clear();
		for(int i=0;i<s.size();i++){
			if(isalnum(s[i])){
				t+=tolower(s[i]);
			}else{
				if(!t.empty()){
					++m[t];
					//cout<<"t:"<<t<<endl;
					t.clear();
				}
			}
		}
		if(!t.empty())
			++m[t];
	}
	map<string ,int>::iterator it;
	int max=-1;
	string maxstr;
	for(it=m.begin();it!=m.end();it++)
		if(it->second > max){
			max=it->second;
			maxstr=it->first;
		}
	cout<<maxstr<<" "<<max<<endl;
	system("PAUSE");
	return 0;
}

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	int t;
	cin>>t;
	vector<int> sum(32);
	for(int i=1;i<=t;i++){
		string stra,strb,strc;
		cin>>stra>>strb>>strc;
		fill(sum.begin(),sum.end(),0);
		cout<<"Case #"<<i<<": ";
		if(stra[0]=='-'&&strb[0]=='-'){
			for(vector<int>::size_type ix=0;ix<stra.size();++ix)
				sum[ix]+=(stra[ix]-'0');
			for(vector<int>::size_type ix=0;ix<strb.size();++ix)
				sum[ix]+=(strb[ix]-'0');
			if(strc[0]!='-')
				cout<<"false"<<endl;
			else{
				
				for(vector<int>::size_type ix=0;ix!=sum.size()-1;++ix){
					sum[ix+1]=sum[ix]/10;
					sum[ix]=sum[ix]%10;
				}
				//string j=str;
				vector<int>::size_type j=sum.size()-1;
				for(string::size_type ix=0;ix!=strc.size();++ix,j--)
					if(sum[j]>)


			}
		}else if(stra[0]=='-'){

		}else if(strb[0]=='-'){

		}else{

		}

		for(string::size_type ix=stra.size()-1;ix>=0;--ix,++j)
			sum[j]+=(stra[ix]-'0');
		j=0;
		for(string::size_type ix=strb.size()-1;ix>=0;--ix,++j)
			sum[j]+=(strb[ix]-'0');
		for(vector<int>::size_type ix=0;ix!=32;++ix)
			if(sum[i])

	}



	return 0;
}
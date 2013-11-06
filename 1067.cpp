#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
const int N = 100005;
int a[N];
int hash[N];
int num=0;
int n;
int swaps=0;

void findswap(){
	if(num==0)
		return;
	for(int i=0;i<n;i++){
		if(a[i]!=i){
			int s=i;
			while(a[s]!=s){
				int t=hash[s];
				a[hash[s]]=a[s];
				hash[a[s]]=hash[s];
				a[s]=s;
				hash[s]=s;
				num--;
				swaps++;
				s=t;
			}
			num--;
			swaps+=2;
		}
	}
	
	//findswap();
}


int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=i)
			num++;
		hash[a[i]]=i;
	}
	if(num==0){
		printf("0\n");
		return 0;
	}

	int s;
	s=hash[0];
	if(s!=0){
		while(s!=0){
			// swap(s,a[s])
			a[hash[s]]=0;
			a[s]=s;
			hash[0]=hash[s];
			hash[s]=s;
			swaps++;
			num--;
			s=hash[0];
		}
		num--;
	}

	findswap();

	

	printf("%d\n",swaps);

	//system("PAUSE");
	return 0;
}
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
const int N = 100005;
int a[N];
int hash[N];
int num=0;
int n;
int swaps=0;

void findswap(){
	if(num==0)
		return;
	for(int i=0;i<n;i++){
		if(a[i]!=i){
			int s=i;
			while(a[s]!=s){
				int t=hash[s];
				a[hash[s]]=a[s];
				hash[a[s]]=hash[s];
				a[s]=s;
				hash[s]=s;
				num--;
				swaps++;
				s=t;
			}
			num--;
			swaps+=2;
		}
	}
	
	//findswap();
}


int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=i)
			num++;
		hash[a[i]]=i;
	}
	if(num==0){
		printf("0\n");
		return 0;
	}

	int s;
	s=hash[0];
	if(s!=0){
		while(s!=0){
			// swap(s,a[s])
			a[hash[s]]=0;
			a[s]=s;
			hash[0]=hash[s];
			hash[s]=s;
			swaps++;
			num--;
			s=hash[0];
		}
		num--;
	}

	findswap();

	

	printf("%d\n",swaps);

	//system("PAUSE");
	return 0;
}

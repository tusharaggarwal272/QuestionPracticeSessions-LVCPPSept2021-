//--------------------------------------------------Finding CB Numbers----------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int cbnumber[10]={2,3,5,7,11,13,17,19,23,29};//why??
bool check(long long int num){
	if(num==0 or num==1)return false;

	for(int i=0;i<10;i++){
		if(num-cbnumber[i]==0)return true;
	}


	for(int i=0;i<10;i++){
		if(num%cbnumber[i]==0)return false;
	}

	return true;
}

bool visornot(bool vis[],int s,int e){
	for(int i=s;i<e;i++){
		if(vis[i]==1)return false;
	}

	return true;
}

int main() {
	int n;
	cin>>n;

	string s;
	cin>>s;
	int count=0;

	bool vis[17];
	for(int i=0;i<17;i++)vis[i]=false;


	for(int l=1;l<=n;l++){
		for(int k=0;k<=n-l;k++){
			int end=k+l;
			string str=s.substr(k,l);

			long long int num=stoll(str);

			if(check(num) and visornot(vis,k,end)){
				count++;
				for(int i=k;i<end;i++)vis[i]=1;
			}
		}
	}


cout<<count;

	return 0;
}

//----------------------------------------------------Calculate The Sum-------------------------------------------------------------
#include<iostream>
using namespace std;
#define int long long int
int mod=1e9+7;
int32_t main() {
	int n;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];

	int q;
	cin>>q;

	while(q--){
		int x;
		cin>>x;

		int temp[n]={0};

		if(x==0){
			for(int i=0;i<n;i++)temp[i]=2*arr[i];
		}else{
			temp[x]=arr[x-x]+arr[x];
			int k=x-1;
			while(k!=x){
				int index=k-x;
				if(index<0)index+=n;
				temp[k]=arr[k]+arr[index];
				k--;
				if(k<0)k=n-1;
			}
		}
		for(int i=0;i<n;i++)arr[i]=temp[i];

	}


	int sum=0;
	for(int i=0;i<n;i++){
		sum+=arr[i];
		sum=sum%mod;
	}
	cout<<sum%mod;

	return 0;
}

//----------------------------------------------------------------Custom Sort String----------------------------------------------------
#include<iostream>
using namespace std;

int main () {

	string order,s;
	cin>>order>>s;

	int freq[123]={0};


	for(int i=0;i<s.length();i++){
		int val=s[i];
		freq[val]++;
	}

	string str="";


	for(int i=0;i<order.length();i++){
		while(freq[order[i]]>0){
			str+=order[i];
			freq[order[i]]--;
		}
		freq[order[i]]=0;
	}

	for(int i=0;i<123;i++){
		while(freq[i]>0){
			str+=i;
			freq[i]--;
		}
	}

	cout<<str;

	return 0;
}

//--------------------------------------------------------------------
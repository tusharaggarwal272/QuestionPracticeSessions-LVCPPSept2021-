
//----------------------------------------------------Smallest distinct window------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int len=INT_MAX;
		int n=s.length();

		int freq1[123]={0},fre2[123]={0};
		int count1=0,count2=0;

		for(int i=0;i<n;i++){
			freq1[s[i]]++;
			if(freq1[s[i]]==1){
				count1++;
			}
		}


		int i=0,j=0;
		while(j<n){
			fre2[s[j]]++;
			if(fre2[s[j]]==1)count2++;


			if(count1==count2){
				while(fre2[s[i]]>1){
					fre2[s[i]]--;
					len=min(len,j-i);
					i++;
				}
			}

			j++;
		}

		cout<<len<<endl;


	}
}

//--------------------------------------------------------------------Piyush and Magical Park--------------------------------------------------------
#include<iostream>
using namespace std;

int main() {
	int n,m,k,s;
	cin>>n>>m>>k>>s;

	char park[n][m];

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>park[i][j];
		}
	}


	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){

			if(s<k){
				cout<<"No";
				return 0;
			}
			if(park[i][j]=='.'){
				s-=2;
			}
			else if(park[i][j]=='*'){
				s+=5;
			}
			else{
				break;
			}

			if(j!=m-1){
				s-=1;
			}
		}
	}


	if(s>=k){
		cout<<"Yes"<<endl;
		cout<<s;
	}
	else{
		cout<<"No";
	}



	
	return 0;
}

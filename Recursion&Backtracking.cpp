//Generate parenthesis **************************************************

#include<bits/stdc++.h>
using namespace std;

void generateparenthesis(int n,int no,int nc,string s){
	//base case

	if(nc==n){
		cout<<s<<" ";
		cout<<endl;
		return;
	}

	if(nc<no){
		generateparenthesis(n,no,nc+1,s+')');
	}
	if(no<n){
		generateparenthesis(n,no+1,nc,s+'(');
	}


}
int main(){
	int n;
	cin>>n;

	int no=0,nc=0;

	generateparenthesis(n,no,nc,"");
}

//**********************************************************
// Recursion Ascii subsequences:

#include<iostream>
using namespace std;

void codes(string s,string str,int i,int n){
	if(s[i]=='\0'){
		cout<<str<<" ";
		return;
	}

	codes(s,str,i+1,n);

	codes(s,str+s[i],i+1,n);

	codes(s,str+to_string(int(s[i])),i+1,n);
	// cout<<str;

	return;


}
int main() {

	string s;
	cin>>s;

	codes(s,"",0,s.length());
	return 0;
}


// ********************************************
// RAt chases its cheese
#include<bits/stdc++.h>
using namespace std;

bool flag=false;//assuming that there will be no path.

void ratchasesitscheese(vector<vector<char>>&v,vector<vector<int>>sol,int i,int j,int n,int m){

	if(i==n and j==m){//final condition
		//base case;
		sol[i][j]=1;
		for(int k=0;k<=n;k++){
			for(int l=0;l<=m;l++){
				cout<<sol[k][l]<<" ";
			}
			cout<<endl;
		}

        // cout<<"**************************************"<<endl;

        flag=true;
		return;

	}


	if(i>n or j>m or v[i][j]=='X' or i<0 or j<0){//they are leading out of the grid or barrier
		return;
	}
		
	sol[i][j]=1;

     if(j-1>=0 and sol[i][j-1]==0)
    ratchasesitscheese(v,sol,i,j-1,n,m);

     if(j+1<=m and sol[i][j+1]==0)
	ratchasesitscheese(v,sol,i,j+1,n,m);

    if(i+1<=n and sol[i+1][j]==0)
	ratchasesitscheese(v,sol,i+1,j,n,m);

    if(i-1>=0 and sol[i-1][j]==0)
    ratchasesitscheese(v,sol,i-1,j,n,m);

   




//


	sol[i][j]=0;


//
return;
}
int main() {

	int n,m;
	cin>>n>>m;

	vector<vector<char>>v(n,vector<char>(m));

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>v[i][j];
		}
	}

	vector<vector<int>>sol(n,vector<int>(m,0));

	ratchasesitscheese(v,sol,0,0,n-1,m-1);

    if(flag==false){
        cout<< "NO PATH FOUND";
    }
	
	return 0;
}

// Board path count

#include<iostream>
using namespace std;

int boardpaths(int cur,int end,int faces,string str){
		//base case
		if(cur==end){
			cout<<str<<" ";
			return 1;
		}

	int count=0;
	for(int dice=1;dice<=faces and dice+cur<=end;dice++){
		count+=boardpaths(cur+dice,end,faces,str+to_string(dice));
	}

	return count;

}
int main() {
	int n;
	cin>>n;

	int faces;
	cin>>faces;

	int ans=boardpaths(0,n,faces,"");
	cout<<endl;
	cout<<ans;
	return 0;
}
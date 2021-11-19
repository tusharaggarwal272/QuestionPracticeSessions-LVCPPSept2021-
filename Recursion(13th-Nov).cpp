


//---------------------Move all x at end------------


#include<iostream>
using namespace std;
string moveallxtoend(string s){

	//base case
	if(s.length()==0)return "";


	char ch=s[0];
	string ros=s.substr(1);
	string res=moveallxtoend(ros);//recursive call 

	if(ch=='x'){
		return res+'x';//
	}
	return ch+res;



}
int main() {

	string s;
	cin>>s;

	// cout<<s.substr(1);


	cout<<moveallxtoend(s);

	return 0;
}



//---------------------------------------------Subsets--------------------------------------------
#include<iostream>
#include<vector>
using namespace std;

void subsets(int arr[],int n,int k,int i,int sum,vector<int>v){
	//base case
	if(sum==k){
		for(int i=v.size()-1;i>=0;i--){
			cout<<v[i]<<" ";
		}
		cout<<endl;
		return;
	}
	if(i>=n or sum>k)return;


	subsets(arr,n,k,i+1,sum,v);//exclude
	v.push_back(arr[i]);
	subsets(arr,n,k,i+1,sum+arr[i],v);//include

}
int main() {
	int n;
	cin>>n;

	int arr[n];

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int k;
	cin>>k;

	vector<int>v;

	subsets(arr,n,k,0,0,v);
	return 0;
}


//------------------------------------------------------House Robber(LeetCode)-----------------------------------------
class Solution {
public:
    int helper(vector<int>&nums,int i){
        //base case
        if(i>=nums.size())return 0;
        
        
        int ans1=nums[i]+helper(nums,i+2);
        int ans2=helper(nums,i+1);
        
        return max(ans1,ans2);
    }
    int rob(vector<int>& nums) {
        return helper(nums,0);
    }
};
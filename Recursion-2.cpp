//code for Recursion-Codes of the string.
#include<bits/stdc++.h>
using namespace std;

char arr[27]={' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
vector<string>v;

void codesofthestring(string s,int i,int n,string str){

//base case
	if(i>=n){
		v.push_back(str);

		return;
	}

		int no=s[i]-'0';

		codesofthestring(s,i+1,n,str+arr[no]);//individual

		if(i+1<=n-1){
			no*=10;
			no+=s[i+1]-'0';

			if(no<=26){
				codesofthestring(s,i+2,n,str+arr[no]);
			}
		}




return;

}


int main() {
	string s;
	cin>>s;
	int n=s.length();

	string str="";

	codesofthestring(s,0,n,str);


	cout<<"[";
	for(int i=0;i<v.size()-1;i++){
		cout<<v[i]<<", ";
		// if(i!=v.size()-1)cout<<", ";
	}
	cout<<v[v.size()-1];
	cout<<"]";
	return 0;
}

// Partition Equal Subset Sum

class Solution {
public:
    bool helper(vector<int>&nums,int sum,int i,int k,int n){
        //base case
        if(k==sum)return true;
        
        if(k>sum or i>=n)return false;
        
        
        return helper(nums,sum,i+1,k,n) || helper(nums,sum,i+1,k+nums[i],n);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto x:nums){
            sum+=x;
        }
        if(sum%2!=0)return false;
        sum/=2;
        
        
        return helper(nums,sum,0,0,n);
    }
};

//Target sum
class Solution {
public:
    int helper(vector<int>&nums,int n,int i,int sum,int target){
        //base case
        
        if(i==n){
            if(sum==target)return 1;
            
            return 0;
        }
        
        
        
        return helper(nums,n,i+1,sum+nums[i],target)+helper(nums,n,i+1,sum-nums[i],target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return helper(nums,n,0,0,target);
    }
};

// Perfect sqaures
class Solution {
public:
    
    int helper(int n){
        //base case
        if(n==0)return 0;
        
        
        
        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++){
            ans=min(ans,helper(n-i*i));
        }
        
        return ans+1;
        
    }
    int numSquares(int n) {
          return helper(n);
    }
};




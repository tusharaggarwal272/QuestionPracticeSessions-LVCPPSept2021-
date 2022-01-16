#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    vector<node*>v;
    int data;
    node(int data){
        this->data=data;
    }
};

node* insert(){
    int d;
    cin>>d;

    node*node1=new node(d);

    int sz;
    cin>>sz;

    for(int i=0;i<sz;i++){
        (node1->v).push_back(insert());
    }

    return node1;

}

void sum(node*root,int &total){
    total+=root->data;

    for(int i=0;i<(root->v).size();i++){
        sum((root->v)[i],total);
    }

}

int main() {

    node*root=insert();
    int total=0;
    sum(root,total);

    cout<<total;

    
}

//shortest unique prefix
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    node* arr[26];
    int count;

    node(){
        this->count=0;
        for(int i=0;i<26;i++){
            arr[i]=NULL;
        }
    }
};


void insert(node*root,string s){
    for(int i=0;i<s.length();i++)
    {
        if(!root->arr[s[i]-'a']){
            root->arr[s[i]-'a']=new node();
            
        }
        root->count++;
        root=root->arr[s[i]-'a'];
    }
}

int shortestprefix(node*root,string s){
    for(int i=0;i<s.length();i++){
        root=root->arr[s[i]-'a'];
        if(root->count==1)return i;
    }

    return s.length();
}


int main() {
    int n;
    cin>>n;
    vector<string>v(n);
    node*root=new node();
    for(int i=0;i<n;i++){
        cin>>v[i];
    insert(root,v[i]);
    }

    for(auto x:v){
        int k=shortestprefix(root,x);
        cout<<x.substr(0,k+1)<<" ";
    }

    
}


//counting bits
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n+1,0);
        
        if(n==0){
            dp[0]=0;
            return dp;
        }
        else if(n==1){
            dp[0]=0;
            dp[1]=1;
            return dp;
        }
        else if(n==2){
            dp[0]=0;
            dp[1]=1;
            dp[2]=1;
            return dp;
        }
        dp[0]=0;
            dp[1]=1;
            dp[2]=1;
        
        
        for(int i=3;i<=n;i++){
            int ones=0;
            int k=i;
            while(k){
                if(k&1)ones++;
                
                k=k>>1;
                if(dp[k]!=-1)break;
            }
            
            dp[i]=dp[k]+ones;
        }
        
        return dp;
    }
};

//russian doles
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& v) {
        int n=v.size();
        sort(v.begin(),v.end());
        
        vector<int>dp(n,1);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(v[j][0]<v[i][0] and v[j][1]<v[i][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        
        
        
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,dp[i]);
        }
        
        
        return maxi;
        
        
        
    }
};

// minimum cost minCostClimbingStairs
class Solution {
public:
    int helper(vector<int>&cost,int i,vector<int>&dp){
        
        if(i>=cost.size())return 0;
        
        if(dp[i]!=-1)return dp[i];
        
        
        return dp[i]=cost[i]+min(helper(cost,i+1,dp),helper(cost,i+2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n=cost.size();
        
        vector<int>dp(n,-1);
        
        return min(helper(cost,0,dp),helper(cost,1,dp));
    }
};
//. Maximum Product of Two Elements in an Array

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int>pq;
        
        for(auto x:nums){
            pq.push(x);
        }
        
        int x=pq.top();
        pq.pop();
        int y =pq.top();
        pq.pop();
        
        return (x-1)*(y-1);
    }
};

//Last Stone Weight

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        
        for(auto x:stones){
            pq.push(x);
        }
        
        while(pq.size()>1){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            
            if(x==y)continue;
            
            pq.push(x-y);
        }
        
        
        return pq.size()!=0?pq.top():0;
    }
};
//K Closest Points to Origin

class Solution {
public:
    #define node pair<int,pair<int,int>>
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<node,vector<node>,greater<node>>pq;
        
        for(auto x:points){
            int dis=(x[0])*(x[0])+(x[1])*(x[1]);
            
            pq.push({dis,{x[0],x[1]}});
            // pq.push(make_pair(dis,make_pair(x[0],x[1])));
        }
        
        
        vector<vector<int>>v;
        
        while(!pq.empty() and k--){
            
            node n=pq.top();
            pq.pop();
            vector<int>d;
            d.push_back(n.second.first);
            d.push_back(n.second.second);
            
            v.push_back(d);
        }
        
        
        
        
        return v;
        
        
        
    }
};

#include<bits/stdc++.h>
using namespace std;
#define int long long int 
int32_t main() {
	priority_queue<int>pq;
	
		int q,k;
		cin>>q>>k;
		while(q--){

		int d;
		cin>>d;

		if(d==2){

			while(pq.size()>k){
				pq.pop();
			}
			cout<<pq.top()<<endl;
		}
		else{

			int x,y;
			cin>>x>>y;

			int dis=pow(x,2)+pow(y,2);
			pq.push(dis);
		}

	}

	return 0;
}
class Solution {
public:
    #define node pair<int,pair<int,int>>
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<node,vector<node>,greater<node>>pq;
        
        int s1=nums1.size();
        int s2=nums2.size();
        
        int m=min(s1,k);
        int n=min(s2,k);
        
        int count=0;
        vector<vector<int>>v;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // count++;
                // if(count>k)break;
                int res=nums1[i]+nums2[j];
                pq.push({res,{nums1[i],nums2[j]}});
                
                // vector<int>d;
                // d.push_back(nums1[i]);
                // d.push_back(nums2[j]);
                // v.push_back(d);
                
                
                
            }
        }
        
        while(k-- and !pq.empty()){
            node n=pq.top();
            pq.pop();
            
            
            vector<int>d;
                d.push_back(n.second.first);
                d.push_back(n.second.second);
                v.push_back(d);
            
            
        }
        
        
        
        return v;
    }
};
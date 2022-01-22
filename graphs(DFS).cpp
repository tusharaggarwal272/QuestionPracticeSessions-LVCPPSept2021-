#include <bits/stdc++.h>
using namespace std;
void dfs(vector<bool>&vis,vector<int>adj[],int cur){

   

    vis[cur]=1;
    for(auto x:adj[cur]){
        if(!vis[x]){
            dfs(vis,adj,x);
        }
    }
     cout<<cur<<" ";

}

int main() {
    int n,m;
    cin>>n>>m;

    vector<int>adj[n+1];

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
    }

    vector<bool>vis(n+1,0);
    dfs(vis,adj,0);

}


class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>indeg(n+1,0);
        vector<int>outdeg(n+1,0);
        
        for(auto x:trust){
            outdeg[x[0]]++;
            indeg[x[1]]++;
        }
        
        for(int i=1;i<=n;i++){
            if(indeg[i]==n-1 and outdeg[i]==0)return i;
        }
        
        return -1;
    }
};

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>indeg(n+1,0);
        vector<int>outdeg(n+1,0);
        
        for(auto x:trust){
            outdeg[x[0]]++;
            indeg[x[1]]++;
        }
        
        for(int i=1;i<=n;i++){
            if(indeg[i]==n-1 and outdeg[i]==0)return i;
        }
        
        return -1;
    }

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    
    void dfs(int cur,vector<bool>&vis,vector<int>adj[],int &V){
        
        vis[cur]=1;
        V-=1;
        
        for(auto x:adj[cur]){
            if(!vis[x]){
                dfs(x,vis,adj,V);
            }
        }
        
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    
	    vector<bool>vis(V+1,0);
	    int no=V;
	    
	    for(int i=0;i<=V;i++){
	        V=no;
	        dfs(i,vis,adj,V);
	        if(V==0)return i;
	    }
	    
	    return -1;
	}

};


class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    
    void dfs(int cur,vector<bool>&vis,vector<int>adj[],int &V){
        
        vis[cur]=1;
        V-=1;
        
        for(auto x:adj[cur]){
            if(!vis[x]){
                dfs(x,vis,adj,V);
            }
        }
        
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    
	    vector<bool>vis(V+1,0);
	    int no=V;
	    
	    for(int i=0;i<=V;i++){
	        V=no;
	        dfs(i,vis,adj,V);
	        if(V==0)return i;
	    }
	    
	    return -1;
	}

};



class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    
    void dfs(int cur,vector<bool>&vis,vector<int>adj[],int &V){
        
        vis[cur]=1;
        V-=1;
        
        for(auto x:adj[cur]){
            if(!vis[x]){
                dfs(x,vis,adj,V);
            }
        }
        
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    
	    vector<bool>vis(V+1,0);
	    int no=V;
	    
	    for(int i=0;i<=V;i++){
	        V=no;
	        dfs(i,vis,adj,V);
	        if(V==0)return i;
	    }
	    
	    return -1;
	}

};
public:
    
    bool dfs(vector<bool>&vis,vector<int>adj[],int count,int cur,int N){
        vis[cur]=1;
        count++;
        
        if(count==N)return true;//one condition for backtrack
        
        for(auto x:adj[cur]){
            if(!vis[x]){
               if(dfs(vis,adj,count,x,N)) return true;
            }
        }
        
        
        //backtracking part
        vis[cur]=0;
        count--;
        return false;
        
    }
    bool check(int N,int M,vector<vector<int>> v)
    {
        // code here
        int count=0;
        vector<int>adj[N+1];
        for(int i=0;i<v.size();i++)
        {
            adj[v[i][0]].push_back(v[i][1]);
            adj[v[i][1]].push_back(v[i][0]);
        }
        
        vector<bool>vis(N+1,0);
        
        for(int i=0;i<=N;i++){
            if(dfs(vis,adj,count,i,N)==true)return 1;
        }
        
        return 0;
        
    }
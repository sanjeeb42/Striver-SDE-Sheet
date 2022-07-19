#include<bits/stdc++.h>

void DFS(vector<int>&ans,int source, unordered_map<int, vector<int>> &adj, vector<bool> &visited)
{
    visited[source]=true;
   
    for(auto it : adj[source])
    {
        if(!visited[it]){
            DFS(ans,it,adj,visited);
        }
    }
     ans.push_back(source);  
}

vector<int> topologicalSort(vector<vector<int>> &edges, int n, int m)  {
    // Write your code here
    
    unordered_map<int,vector<int>>adj;
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0], v=edges[i][1];
        adj[u].push_back(v);
    }
    
    for(int i=0;i<n;i++)
    {
        sort(adj[i].begin(),adj[i].end());
    }
    
    vector<int>ans;
    vector<bool>visited(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
             DFS(ans,i,adj,visited);
        }
    }
   reverse(ans.begin(),ans.end());
    return ans;
   
}

#include<bits/stdc++.h>
void DFS(int i,vector<bool>&visited,unordered_map<int,vector<int>>&mp,vector<int>&ans)
{
    // Real Game begin
    ans.push_back(i);
    visited[i]=true;
    for(auto it: mp[i]){
        if(!visited[it]){
            DFS(it,visited,mp,ans);
        }
    }  
}

vector<vector<int>> depthFirstSearch(int v, int E, vector<vector<int>> &edges)
{
    // Write your code here   
    unordered_map<int,vector<int>>mp;
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0], v=edges[i][1];
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    
    //Now real game starts
    vector<bool>visited(v,false);
    for(int i=0;i<v;i++)
     {
       sort(mp[i].begin(),mp[i].end());
     }
    
    vector<vector<int>>ans;
   
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        { 
            vector<int>curr_ans;
             DFS(i,visited,mp,curr_ans);
             ans.push_back(curr_ans);
         }
    }
    return ans;
}

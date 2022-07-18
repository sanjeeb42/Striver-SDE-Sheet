#include<bits/stdc++.h>

bool BFS(int i,vector<bool>&visited,unordered_map<int,vector<int>>&mp){    
    // Steps are Firstly take out the front node
    queue<pair<int,int>>q;
    q.push({i,-1});
    visited[i]=true;
    while(q.size()>0)
    {
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
              
        for(auto it: mp[node])
        {
            if(!visited[it])
            {
                q.push({it,node});
                visited[it]=true;
                
            }
            
            else if(visited[it]){
                 if(parent!=it){
                     return false;
                 }
            }
        }
    }
    return true;    
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
     unordered_map<int,vector<int>>mp;
    for(int i=0;i<m;i++)
    {
        int u=edges[i][0], v=edges[i][1];
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    
    //Now real game starts
    vector<bool>visited(n,false);
    for(int i=0;i<n;i++){
       sort(mp[i].begin(),mp[i].end());
       //mp[i].sort()
    }
    
    
    bool ans=true;
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            ans=ans and BFS(i,visited,mp);
        }
    }   
    return ans!=true?"Yes":"No";
    
    
}

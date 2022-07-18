#include<bits/stdc++.h>

void printBFS(int i,vector<int>&ans,vector<bool>&visited,unordered_map<int,vector<int>>&mp){    
    // Steps are Firstly take out the front node
    queue<int>q;
     q.push(i);
     visited[i]=true;
    while(q.size()>0)
    {
        int front=q.front();
        q.pop();
        ans.push_back(front);
        
           for(auto it: mp[front]){
            if(!visited[it])
            {
                q.push(it);
                visited[it]=true;
                
            }
        }
    }
    return;    
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    // Getting the adjacency list representation first
    unordered_map<int,vector<int>>mp;
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i].first, v=edges[i].second;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    
    //Now real game starts
    vector<bool>visited(vertex,false);
   for(int i=0;i<vertex;i++){
       sort(mp[i].begin(),mp[i].end());
       //mp[i].sort()
   }
    
    vector<int>ans;
    
    for(int i=0;i<vertex;i++)
    {
        if(visited[i]==false)
        {           
            printBFS(i,ans,visited,mp);            
        }    
    }
    
    return ans;
  
}

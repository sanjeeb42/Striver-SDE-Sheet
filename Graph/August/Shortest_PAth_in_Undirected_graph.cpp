#include<bits/stdc++.h>

void solve(map<int,vector<int>>&mp,int node,vector<int>&distance,vector<int>&visited){
    
    queue<int>q;
    q.push(node);
    visited[node]=1;
    
    while(q.size()>0)
    {
        int front=q.front();q.pop();
        for(auto it: mp[front])
        {           
            distance[it]=min(distance[it],distance[front]+1);
           if(!visited[it])
           { 
               q.push(it);
               visited[it]=1;
           }     
        }
    }  
}

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	vector<int>distance(n+1,1e8);
    distance[s]=0;
    vector<int>visited(n+1,0);
    map<int,vector<int>>mp;
    for(auto it: edges)
    {
       
        int u=it.first, v=it.second;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    
    solve(mp,s,distance,visited);
    vector<int>fans;
    for(auto it: distance)
    {
        cout<<it<<" ";
    }
    
    return distance;  
}

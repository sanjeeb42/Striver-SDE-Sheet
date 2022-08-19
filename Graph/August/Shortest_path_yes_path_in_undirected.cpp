#include<bits/stdc++.h>


vector<int> find_parent(unordered_map<int,vector<int>>&mp,int node,int n,int end)
{    
//      parent[node]=-1;
    unordered_map<int,int>parent; 
     unordered_map<int,bool>visited;           
     queue<int>q;
     q.push(node);             
     visited[node]=true;
    while(q.size()>0)
    {
        int front=q.front();
        q.pop();
        
        for(auto it: mp[front]){
            if(!visited[it])
            {
                visited[it]=true;
                parent[it]=front;
                q.push(it);
            }
        }
    }
    vector<int>fans;
    int dest=end;
    fans.push_back(end);
    while(dest!=node)
    {
        dest=parent[dest];
        fans.push_back(dest);
       
    }
   // fans.push_back(dest);
    reverse(fans.begin(),fans.end());
    return fans;                 
}



vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
    unordered_map<int,vector<int>>mp;  
    
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i].first;
        int v=edges[i].second;
        
        mp[u].push_back(v);
        mp[v].push_back(u);
    }    
      
    vector<int>ans=find_parent(mp,s,n,t);
    return ans;
   
}

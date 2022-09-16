class Solution {
  public:
  
  
  int shortestpath(unordered_map<int,vector<pair<int,int>>>&mp,int src,int dest,int n){
    vector<int>distance(n,1e9);
    distance[src]=0;
    
    // if(src==dest)return 0;
    
    queue<pair<int,int>>q;
    q.push({src,0});
    
    while(q.size()>0){
        
        auto tmp=q.front();
        auto node=tmp.first;
        int dist=tmp.second;
        q.pop();
        
        
        for(auto it: mp[node])
        {
            if(distance[it.first]>dist+it.second){
                distance[it.first]=dist+it.second;
                q.push({it.first,dist+it.second});
            }
        }   
    }
    
   return distance[dest]; 
}

int dfs(unordered_map<int,vector<pair<int,int>>>&mp,int src,int dest,int mini)
{

    queue<pair<int,int>>q;
    q.push({src,0});
    
    int ans=0;
    
   while(q.size()>0)
   {
    
    
      auto t=q.front();
      q.pop();
    
      int node=t.first, distance=t.second;
      
      if(node==dest && distance==mini){
          ans++;
      }
      
      for(auto it:mp[node])
      {
          if(distance + it.second<=mini)
          {
              q.push({it.first,distance+it.second});
          }
      }
   }
   
   return ans;
  
}


    int countPaths(int n, vector<vector<int>>& edges) 
{
        // code here
        
    unordered_map<int,vector<pair<int,int>>>mp;
    for(auto it: edges)
    {
        int u=it[0], v=it[1], weight=it[2];
        mp[u].push_back({v,weight});
        mp[v].push_back({u,weight});
    }
    
    //Finding Minimum Path
    
    int len= shortestpath(mp,0,n-1,n);
    if(len==1e9)return 0;
    
    //Now Time to Find all the paths
    
    //Its Time for dfs bruh
    
    return dfs(mp,0,n-1,len);
    }
};

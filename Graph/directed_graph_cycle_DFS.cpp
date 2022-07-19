bool isCycle(int i,unordered_map<int,vector<int>>&mp,vector<bool>&visited,vector<bool>&recStack)
{
    visited[i]=true;
    recStack[i]=true;
    
    for(auto it: mp[i])
    {
         if(visited[it]==true && recStack[it]==true)
        {   
            return true;
        }     
        else if(!visited[it])
        {
            bool tmp=isCycle(it,mp,visited,recStack);
            if(tmp){
                return true;
            }
        }
      
    }
    recStack[i]=false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
    
    //Unordered Map adjacency Matrix
    unordered_map<int,vector<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first, v=edges[i].second;
        adj[u].push_back(v);
    }
    
    //Now we go for some other parts 
    
    vector<bool>visited(n+1,false);
    vector<bool>recStack(n+1,false);
   
    for(int i=1;i<=n;i++)
    {      
        if(!visited[i])
        {
            if(isCycle(i,adj,visited,recStack))return 1; 
        }
    }
    
    return 0;
  
}

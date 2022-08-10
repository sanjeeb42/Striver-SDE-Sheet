bool solve(int node,vector<int>adj[],vector<int>&recStack,vector<int>&visited){
      
      visited[node]=1;
      recStack[node]=1;
      
      //Recursive case
      
      for(auto &it: adj[node])
      {
       
         if(!visited[it])
         {
              if(solve(it,adj,recStack,visited))return true;
         }
         else if(recStack[it])return true;
         
          
      }
      recStack[node]=0;
      return false;
     
  }
  
  
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        vector<int>recStack(V+1,0);
        vector<int>visited(V+1,0);
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(solve(i,adj,recStack,visited))return true;
            }
        }
        return false;
        
    }

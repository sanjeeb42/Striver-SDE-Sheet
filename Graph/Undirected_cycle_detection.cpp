 bool DFS(vector<int>adj[],int parent,int node,vector<int>&visited){
        
        
        //Base Case
        if(visited[node])return true;
        visited[node]=1;
        //Recursive Calls
        bool ans=false;
        for(auto it :adj[node]){
            if(it==parent)
            {
                continue;
            }
            ans=ans or DFS(adj,node,it,visited);
        }
        
        return ans;
    }
    
  
    bool isCycle(int V, vector<int> adj[]) 
    {
        vector<int>visited(V+1,0);
        for(int i=0;i<V;i++){
            if(!visited[i])
            {
                if(DFS(adj,-1,i,visited))
                {
                  // cout<<i<<endl;
                    return true;
                }
            }
        }
        return false;
    }
    
    
    
    // bool solve(int node,vector<int>&visited,vector<int>adj[]){
    //     queue<pair<int,int>>q;
        
    //     q.push({node,-1});
    //     visited[node]=1;
        
    //     while(q.size()>0)
    //     {
    //         int parent=q.front().first;
    //         int sec=q.front().second;
    //         q.pop();
            
    //         for(auto it: adj[parent]){
    //             if(it==sec){
    //                 continue;
    //             }
    //             if(visited[it])return true;
    //             q.push({it,parent});
    //             visited[it]=1;
    //         }
    //     }
        
    //     return false;
        
        
    // }
    // bool isCycle(int V, vector<int> adj[]) {
    //     // Code here
        
    //     vector<int>visited(V+1,0);
    //     for(int i=0;i<V;i++){
    //         if(!visited[i])
    //         {
    //             if(solve(i,visited,adj))
    //             {
    //               // cout<<i<<endl;
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }

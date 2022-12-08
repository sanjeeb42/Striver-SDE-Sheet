  bool dfs(vector<int>adj[],int node,vector<int>&visited,vector<int>&PathVisited){
        
        //Base Case wehen it will be false is if Visited & pathvisited boath are true
        
        visited[node]=1;
        PathVisited[node]=1;
        vector<int>curr=adj[node];
        for(auto it: curr){
            if(visited[it]==0){
                if(dfs(adj,it,visited,PathVisited))return true;
            }
            else if(PathVisited[it])return true;
        }
        PathVisited[node]=0;
        
        return false;
    }
    
    // Function to detect cycle in a directed graph.
    bool isCyclic(int n, vector<int> adj[]) {
        // code here
        //We already have the adjacency List 
        
        vector<int>visited(n,0);
        vector<int>PathVisited(n,0);
        
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                if(dfs(adj,i,visited,PathVisited)==true)return true;
            }
        }
        
        return false;
    }

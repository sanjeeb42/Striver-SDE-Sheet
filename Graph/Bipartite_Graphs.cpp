bool solve(int node,int parent,vector<int>&visited,vector<int>adj[],vector<int>&color,int curr_color)
    {
        
        if(visited[node] and color[node]!=curr_color)
        {
          //  cout<<"Not Entered"<<endl;
            return false;
        }
        
        else if(visited[node] and color[node]==curr_color)return true;
        
        visited[node]=1;
        color[node]=curr_color;
        
        bool ans=true;
        for(auto it:adj[node])
        {
            if(it==parent)continue;
            
            ans=ans and solve(it,node,visited,adj,color,1-curr_color);
            
        }
        
        return ans;
    }
    

	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    
	    //Using DFS
	    
	    vector<int>color(V+1,-1);
	    vector<int>visited(V+1,0);
	    
	    
	    for(int i=0;i<V;i++)
	    {
	        if(!visited[i])
	        {
	            if(solve(i,-1,visited,adj,color,0)==false)return false;
	        }
	    }
	    
	    return true;
	}

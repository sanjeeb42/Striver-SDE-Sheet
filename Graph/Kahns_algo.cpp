	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>indegree(V,0);
	    vector<bool>visited(V,false);
	    unordered_map<int,vector<int>>mp;
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:adj[i])
	        {
	            mp[i].push_back(it);
	            
	        }
	    }
	   
	    for(auto it: mp){
	        for(auto pq:it.second){
	            indegree[pq]++;
	        }
	    }
	    vector<int>ans;
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            q.push(i);
	            visited[i]=true;
	        }
	    }
	    while(q.size()>0){
	        
	        int front=q.front();
	        q.pop();
	        ans.push_back(front);
	        for(auto it: mp[front])
	        {
	            if(!visited[it]){
	                indegree[it]--;
	                if(indegree[it]==0){
	                    q.push(it);
	                visited[it]=true;
	                }
	            }
	        }
	    }
	   
	    return ans;
	}

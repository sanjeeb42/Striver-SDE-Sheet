 vector<pair<int,int>>grid={{2,1},{-2,1},{-2,-1},{2,-1},{1,2},{-1,2},{-1,-2},{1,-2}};

    bool isvalid(int i,int j,int n)
    {
        if(i<0 or j<0 or i>=n or j>=n)return false;
        return true;
    }
	int minStepToReachTarget(vector<int>&start, vector<int>&target, int N){
	    // Code here
	    
	    
	    vector<vector<int>>visited(N+1,vector<int>(N+1,0));
	    queue<vector<int>>q;
	    int ans=0;
	    
	    
	    int f_row=target[0]-1, f_col=target[1]-1;
	    int s=start[0]-1, e=start[1]-1;
	    
	    if(f_row==s && f_col==e)return ans;
	    
	    
	    q.push({s,e,0});
	    visited[s][e]=1;
	    
	    while(q.size()>0)
	    
	    {
	        auto front=q.front();
	        q.pop();
	        int st=front[0], ed=front[1],step=front[2];
	        if(st==f_row && ed==f_col)
	        {
	            ans=step;
	            break;
	        }
	        
	       
	        
	        for(int k=0;k<8;k++)
	        {
	            if(isvalid(st+grid[k].first, ed+grid[k].second,N) && visited[st+grid[k].first][ed+grid[k].second]==0)
	            {
	                visited[st+grid[k].first][ed+grid[k].second]=1;
	                q.push({st+grid[k].first,ed+grid[k].second,step+1});
	            }
	        }
	        
	    }
	    
	    return ans;
	    
	    
	}

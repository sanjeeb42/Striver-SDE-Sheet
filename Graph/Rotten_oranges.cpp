 public:
    
    vector<int>dx={-1,0,1,0};
    vector<int>dy={0,1,0,-1};
    //Function to find minimum time required to rot all oranges. 
    bool isValid(int i,int j,vector<vector<int>>&grid,vector<vector<bool>>&visited)
    {
        int n=grid.size(), m=grid[0].size();
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]!=1 or visited[i][j]==true)return false;
        return true;
    }
    int solve(vector<vector<int>>&grid)
    {
        int n=grid.size(), m=grid[0].size();
        
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        queue<vector<int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    visited[i][j]=1;
                    q.push({i,j,0});
                }
                  
                
            }
        }
        
        int ans=0;
        while(q.size()>0)
        {
            auto front=q.front();
            q.pop();
            
            int i=front[0], j=front[1],steps=front[2];
            ans=max(ans,steps);
            for(int k=0;k<4;k++)
            {
                int newx=i+dx[k], newy=j+dy[k];
                if(isValid(newx,newy,grid,visited)){
                    visited[newx][newy]=true;
                    q.push({newx,newy,steps+1});
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && visited[i][j]!=1){
                    ans=-1;
                    break;
                }
            }
        }
        return ans;
        
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
       return solve(grid);
    }

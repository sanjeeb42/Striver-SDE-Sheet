 vector<int>dx={-1,-1,-1,0,0,1,1,1};
    vector<int>dy={-1,0,1,-1,1,-1,0,1};
    
    int solve(vector<vector<int>>&grid,int i,int j,vector<vector<bool>>&visited)
    {
         int n=grid.size(), m=grid[0].size();
         if(i>=n or j>=m or i<0 or j<0 or grid[i][j]==0 or visited[i][j]==true){
             return 0;
         }
         visited[i][j]=true;
         int tmp_ans=0;
         for(int k=0;k<8;k++)
         {
             int newx=i+dx[k];
             int newy=j+dy[k];
            
             tmp_ans+=solve(grid,newx,newy,visited);
         }
         
         return tmp_ans+1;
    }
    int findMaxArea(vector<vector<int>>& grid)
    {
        // Code here
        int n=grid.size(), m=grid[0].size();
        
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        
         
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j])
                {
                    ans=max(ans,solve(grid,i,j,visited));
                }
            }
        }
        
        return ans;
        
    }

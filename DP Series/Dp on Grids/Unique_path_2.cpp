int solve(vector<vector<int>>&dp,int row,int colm,vector<vector<int>>&grid){
        int n=grid.size(), m=grid[0].size();
        if(row>=n or colm>=m)return 0;
      if(grid[row][colm]==1)return 0;
        if(row==n-1 && colm==m-1)return 1;
        
        
        if(dp[row][colm]!=-1)return dp[row][colm];
        
        int down=solve(dp,row+1,colm,grid);
        int right=solve(dp,row,colm+1,grid);
        
        return dp[row][colm]=down+right;        
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid)
    {
         int n=grid.size(), m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(dp,0,0,grid);
    }

// Efficient Approach

int combination(int n,int r)
{
    int ans=1;
    for(int i=0;i<r;i++)
    {
        ans*=(n-i);
        ans/=(i+1);

    }
    return ans;
}

int uniquePaths(int m, int n) {
	// Write your code here.
    
    int down=m-1, right=n-1;
    int total_move=m+n-2;
    
    int ans=combination(total_move,min(down,right));
    return ans;
}


// DP Approach

int path(vector<vector<int>>&dp,int m,int n,int row,int col)
{
    if(row<0 or col<0)
    {
          return 0;
    }
    else if(row==0 and col==0)
    {
        return 1;
    }
    
    if(dp[row][col]!=-1)
    {
        return dp[row][col];
    }
    // Go up
    int down=path(dp,m,n,row-1,col);
    // Go left
    int right=path(dp,m,n,row,col-1);
    
    return dp[row][col]=down+right;
   
}

int uniquePaths(int m, int n) {
    // Write your code here.
    if(m==1 and n==1)
    {
        return 1;
    }
    vector<vector<int>>dp(m,vector<int>(n,-1));
    int ans=path(dp,m,n,m-1,n-1);

    return dp[m-1][n-1];
    
    
}

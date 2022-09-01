 int solve(vector<vector<int>>&matrix,int i,int j,int &maxi,vector<vector<int>>&dp){
        
        int n=matrix.size(), m=matrix[0].size();
        //base case
        if(i>=n or j>=m)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        int right=solve(matrix,i,j+1,maxi,dp);
        int down=solve(matrix,i+1,j,maxi,dp);
        int diagonal=solve(matrix,i+1,j+1,maxi,dp);
        
        
        if(matrix[i][j]==0)return dp[i][j]=0;
        else if(matrix[i][j]==1)
        {
            int ans=1+min(diagonal,min(right,down));
            maxi=max(maxi,ans);
            return dp[i][j]=ans;
        }
        
        return 1;
        
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        int maxi=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        solve(mat,0,0,maxi,dp);
        
        return maxi;
        
    }

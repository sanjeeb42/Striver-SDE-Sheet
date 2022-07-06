class Solution
{
    public:
//         int path(int m, int n,vector<vector<int>>&dp)
//         {
//             if (m == 0 and n == 0) return 1;
//             if (m < 0 or n < 0) return 0;
//            	//Go up
//             if(dp[m][n]!=-1)return dp[m][n];
//             int up = path(m - 1, n,dp);
//            	//Go left
//             int left = path(m, n - 1,dp);

//             return dp[m][n]=up + left;
//         }
    
    
    int fact(int n,int r){
        //ncr calculation
        long long ans=1;
        int t=r;
        for(int i=1;i<=t;i++)
        {
            ans=(ans*n)/i;
            n--;
        }
        
        return (int)(ans);
    }

    int uniquePaths(int m, int n)
    {
        // vector<vector<int>>dp(m,vector<int>(n,0));
        // dp[0][0]=1;
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(i==0 && j==0)continue;
        //         int down=0, right=0;
        //         if(i>0){
        //             down=dp[i-1][j];
        //         }
        //         if(j>0){
        //             right=dp[i][j-1];
        //         }
        //         dp[i][j]=down+right;
        //     }
        // }
        //     return dp[m-1][n-1];
        // return path(m-1, n-1,dp);
        
        
        
        int top=m+n-2;
        int bottom=min(m-1,n-1);
        
        return fact(top,bottom);
        
        
    }
};

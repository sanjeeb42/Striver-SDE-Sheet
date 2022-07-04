class Solution{
  public:
    
  
    int cutRod(int price[], int n) {
        //code here
        vector<int>length(n);
        for(int i=1;i<=n;i++)
        {
           length[i-1]=i; 
        }
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        //If length==0, Then profit ==0
        //if index==0, return 0
       
    //   for(int i=0;i<=n;i++){
    //       dp[0][i]=INT_MIN;
    //   }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
            {
                if(j>=length[i-1])
                {
                    dp[i][j]=max(dp[i-1][j], price[i-1]+dp[i][j-length[i-1]]);
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        
     
        return dp[n][n];
        
    }
};

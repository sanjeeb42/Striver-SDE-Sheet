int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
     vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
   // return solve(dp,prices,0,0);
    
    for(int index=n-1;index>=0;index--)
    {
        for(int trans=2*k-1;trans>=0;trans--)
        {
             if(trans%2==0)
            {
              dp[index][trans]=max(-prices[index]+dp[index+1][trans+1],
                             0+dp[index+1][trans]);
            }
            else 
            {
               dp[index][trans]=max(prices[index]+dp[index+1][trans+1],
                             0+dp[index+1][trans]);
            }
        }
    }
  return dp[0][0];  
}

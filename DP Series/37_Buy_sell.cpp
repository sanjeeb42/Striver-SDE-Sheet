int solve(vector<vector<int>>dp,vector<int>&prices,int index,int trans){
    //Base case
    if(trans==4 or index==prices.size()) return 0;
    
    //
    if(dp[index][trans]!=-1) return dp[index][trans];
    
    // if(trans) performed is even then its a buy call
    if(trans%2==0)
    {
   return dp[index][trans]=max(-prices[index]+solve(dp,prices,index+1,trans+1),
                             0+solve(dp,prices,index+1,trans));
    }
    else 
    {
    return dp[index][trans]=max(prices[index]+solve(dp,prices,index+1,trans+1),
                             0+solve(dp,prices,index+1,trans));
    }
}


int maxProfit(vector<int>& prices, int n)
{
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return solve(dp,prices,0,0);
    
}

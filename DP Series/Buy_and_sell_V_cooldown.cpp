int solve(vector<vector<int>>&dp,vector<int>&prices,int index,int buy){
    //Base case
    if(index>=prices.size()) return 0;
    
    //
    if(dp[index][buy]!=-1) return dp[index][buy];
    
    // if(trans) performed is even then its a buy call
    if(buy==1){
      return dp[index][buy]=max(-prices[index]+solve(dp,prices,index+1,0),
                             0+solve(dp,prices,index+1,1));
    }
   
    return dp[index][buy]=max(prices[index]+solve(dp,prices,index+2,1),
                             0+solve(dp,prices,index+1,0));
   
}

int stockProfit(vector<int> &prices){
    // Write your code here.
//     int n=prices.size();
//     vector<vector<int>>dp(n+2,vector<int>(2,0));
    
//     for(int index=n-1;index>=0;index--)
//     {
//         for(int buy=0;buy<=1;buy++){
//              if(buy==1)
//              {
//                     dp[index][buy]=max(-prices[index]+dp[index+1][0],
//                              0+dp[index+1][1]);
//     }
//     else 
//     {        
//          dp[index][buy]=max(prices[index]+dp[index+2][1],
//                           0+dp[index+1][0]);
//     }
//         }
//     }
//     return dp[0][1];
    
    
     int n=prices.size();
   vector<int>curr(2,0);
    vector<int>after(2,0);
    vector<int>after_after(2,0);
    
    for(int index=n-1;index>=0;index--)
    {
        for(int buy=0;buy<=1;buy++){
             if(buy==1)
             {
                    curr[buy]=max(-prices[index]+after[0],
                             0+after[1]);
    }
    else 
    {        
         curr[buy]=max(prices[index]+after_after[1],
                          0+after[0]);
    }
        }
        
        after_after=after;
        after=curr;
    }
    return curr[1];
    
}

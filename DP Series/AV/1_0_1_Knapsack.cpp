#include<bits/stdc++.h>

int solve(vector<vector<int>>&dp,vector<int> &values, vector<int> &weights, int index, int w){
    if(index==0 or w==0) return 0;
    if(dp[index][w]!=-1) return dp[index][w];
    
    // Two caese 
    if(weights[index-1]<=w){
        // Pick or not pic maximum
        return dp[index][w]=max(values[index-1]+solve(dp,values,weights,index-1,w-weights[index-1]),
                                 solve(dp,values,weights,index-1,w));
    }
    
    // 2nd case
    else if(weights[index-1]>w)
    {
        return dp[index][w]=solve(dp,values,weights,index-1,w);
    }
}


int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
//     vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
//     return solve(dp,values,weights,n,w);
     vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
    
    //base case
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }   
    for(int j=0;j<=w;j++){
        dp[0][j]=0;
    }
    
    //recursive cases
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++)
        {
            if(weights[i-1]<=j)
            {
                // Pick or not pic maximum
               dp[i][j]=max(values[i-1]+dp[i-1][j-weights[i-1]],
                                 dp[i-1][j]);
            }
            
            else if(weights[i-1]>j)
            {
               dp[i][j]=dp[i-1][j];
            }    
        }
    }
    
   return dp[n][w];
    
}

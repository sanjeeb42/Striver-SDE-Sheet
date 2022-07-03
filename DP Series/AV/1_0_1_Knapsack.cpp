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
    vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
    return solve(dp,values,weights,n,w);
    
}

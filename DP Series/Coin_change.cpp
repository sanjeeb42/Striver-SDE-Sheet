#include<bits/stdc++.h>

long solve(vector<vector<long>>&dp,int *denominations,int index, int n, int value)
{
    if(index>=n)return 0;
    if(value==0)return 1;
    if(value<0)return 0;
    if(dp[index][value]!=-1)return dp[index][value];
    long long ans=0;
    //Take -we have two option
    //Take and Remain on same
    ans+=max(solve(dp,denominations,index,n,value- denominations[index]),solve(dp,denominations,index+1,n,value-denominations[index]));
    
    //Not take
    ans+=solve(dp,denominations,index+1,n,value); 
    return dp[index][value]=ans;   
}


long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    //sort(denominations,denominations+n);
    vector<vector<long>>dp(n+1,vector<long>(value+1,-1));
   long ways= solve(dp,denominations,0,n,value);
    return ways;
}

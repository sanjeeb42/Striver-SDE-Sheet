int ways(vector<int>&nums,int target,vector<int>&dp){
    if(target==0)return 1;
    if(target<0)return 0;
    if(dp[target]!=-1)return dp[target];
    int n=nums.size();
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=ways(nums,target-nums[i],dp);
    }
    return dp[target]=ans;
}

int findWays(vector<int> &nums, int target)
{
    // Write your code here.
    vector<int>dp(target+1,0);  
    dp[0]=1;
    int n=nums.size();
    
    for(int i=1;i<=target;i++){
       int ans=0;
        for(int j=0;j<n;j++)
        {
            if(i-nums[j]>=0){
                  ans+=dp[i-nums[j]];
            }
        }
       dp[i]=ans;
    }
    
    return dp[target];
}

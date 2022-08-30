int solve(vector<int>&dp,vector<int>&nums,int target){
    
    int n=nums.size();
    if(target==0)return 1;
    
    if(dp[target]!=-1)return dp[target];
    int tmp_ans=0;
    
    for(int i=0;i<n;i++)
    {
        if(nums[i]<=target)
        {
            tmp_ans+=solve(dp,nums,target-nums[i]);
        }
    }
    
    return dp[target]=tmp_ans;
    
}

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    vector<int>dp(tar+1,-1);
    return solve(dp,num,tar);
}

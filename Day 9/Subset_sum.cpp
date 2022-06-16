void solve(vector<int>&ans,vector<int>nums,int index,int curr_sum){
    if(index==nums.size()){
        ans.push_back(curr_sum);
        return;
    }
    // Two case available
    //Not Pick
    solve(ans,nums,index+1,curr_sum);
    //Pick
    solve(ans,nums,index+1,curr_sum+nums[index]);
}

vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int>ans;
    solve(ans,num,0,0);
    sort(ans.begin(),ans.end());
    return ans;
    
}

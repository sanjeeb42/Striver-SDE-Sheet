//Iterative -O(2^n * n)time and O(1) space

vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int>ans;
    int n=num.size();
    int no=1<<num.size();
    for(int i=no-1;i>=0;i--){
        int curr_sum=0;
        
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                curr_sum+=num[j];
            }
        }
        ans.push_back(curr_sum);
    }
    sort(ans.begin(),ans.end());
    return ans;
}


//recursive -O(2^n) time and O(n) space

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

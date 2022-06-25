#include<bits/stdc++.h>
int cnt=0;
void solve(vector<vector<int>>&ans,vector<int>&nums,int index,vector<int>&curr){ 

    ans.push_back(curr);
    
    for(int i=index;i<nums.size();i++)
    {
        //Avoiding Duplicates
        if(nums[i]==nums[i-1] && i!=index) {continue;}
        // Else generating a list of size n+1 every time
        curr.push_back(nums[i]);
        solve(ans,nums,i+1,curr);
        curr.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>>ans;
    vector<int>curr;
    sort(arr.begin(),arr.end());
    solve(ans,arr,0,curr);
    return ans;
    
}






// without sorted order using Recursion

#include<bits/stdc++.h>
void solve(vector<vector<int>>&ans,vector<int>nums,int index,vector<int>curr){
    if(index==nums.size())
    {      
        if(find(ans.begin(),ans.end(),curr)==ans.end())
        {
            ans.push_back(curr);
        }
        return;
    }
    // Two case available
    //Not Pick
    solve(ans,nums,index+1,curr);
    //Pick
    curr.push_back(nums[index]);
    solve(ans,nums,index+1,curr);
   // curr.pop_back();
}





vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>>ans;
    vector<int>curr;
    solve(ans,arr,0,curr);
    return ans;
    
}


// Iterative_unsorted

#include<bits/stdc++.h>
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>>ans;
    ans.push_back({});
    for(int i=0;i<n;i++)
    {
        vector<int>curr;
        for(int j=i;j<n;j++){
            curr.push_back(arr[j]);
            if(find(ans.begin(),ans.end(),curr)==ans.end())
            {
                ans.push_back(curr);
            }
        }
        
    }
    return ans;
}

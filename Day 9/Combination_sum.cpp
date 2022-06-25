#include<bits/stdc++.h>

void solve(vector<vector<int>>&ans,vector<int>&arr,vector<int>&curr,int target,int index){
    
    if(target==0) {
        ans.push_back(curr);
        return;
    }
    for(int i=index;i<arr.size();i++){
        if(i!=index && arr[i]==arr[i-1])continue;
        curr.push_back(arr[i]);
        solve(ans,arr,curr,target-arr[i],i+1);
        curr.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
    vector<vector<int>>finalans;
    sort(arr.begin(),arr.end());
    vector<int>curr;
    solve(finalans,arr,curr,target,0);
    return finalans;
}

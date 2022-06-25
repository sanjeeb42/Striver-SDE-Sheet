#include<bits/stdc++.h>

void solve(vector<vector<int>>&ans,vector<int>&arr,int index,int target,vector<int>&curr)
{
    if(target==0){
        ans.push_back(curr);
    }
    
    if(index>=arr.size()) return;
    
    // pick and not pick;  
    for(int i=index;i<arr.size();i++){
   // solve(ans,arr,index+1,target,curr);
    curr.push_back(arr[i]);
    solve(ans,arr,i+1,target-arr[i],curr);
    curr.pop_back();
    }
}


vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    
    vector<vector<int>>ans;
//     set<vector<int>>ans;
    vector<int>curr;
    solve(ans,arr,0,k,curr);
    
//     for(auto it: ans){
//         finalans.push_back(it);
//     }
    
    return ans;
    
}

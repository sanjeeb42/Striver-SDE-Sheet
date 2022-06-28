#include<bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    // Write your code here. 
    int n=arr.size();
    vector<int>ans;
    for(int i=0;i<n;i++){
        int m=arr[i].size();
        for(int j=0;j<m;j++){
            ans.push_back(arr[i][j]);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}

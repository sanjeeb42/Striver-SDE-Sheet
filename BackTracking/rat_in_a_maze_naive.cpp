#include<bits/stdc++.h>



void solve(vector<string>&ans,vector<vector<int>>&arr,int n,string curr,int i,int j,int prev){
    if(i==n-1 && j==n-1){
        ans.push_back(curr);
        return;
    }
    
    if(i<0 or j<0 or i>=n or j>=n) return ;
    if(arr[i][j]==0) return;
    if(prev!=3)solve(ans,arr,n,curr+'U',i-1,j,1);
    if(prev!=4)solve(ans,arr,n,curr+'R',i,j+1,2);
    if(prev!=1)solve(ans,arr,n,curr+'D',i+1,j,3);
    if(prev!=2)solve(ans,arr,n,curr+'L',i,j-1,4);
 
}


vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    if(arr[n-1][n-1]==0) return {};
    string curr="";
    vector<string>ans;
    solve(ans,arr,n,curr,0,0,0);
    sort(ans.begin(),ans.end());
    return ans;
}

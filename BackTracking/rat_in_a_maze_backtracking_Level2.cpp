#include<bits/stdc++.h>

bool isrange(int i,int j,int n){
    if(i>=0 && i<n && j>=0 && j<n)return true;
    return false;
}

void solve(vector<vector<int>>&visited,vector<vector<int>>&ans,vector<vector<int>>&arr,int n,vector<int>curr,int i,int j){
    if(i==n-1 && j==n-1)
    {
        ans.push_back(curr);
        return;
    }
     if(arr[i][j]==0) return;
    
     visited[i][j]=1; 
    curr[i*n + j]=1;
    
    
    //try all 4 possible ways if allowed
    
    //U L D R ---> Lexicographic D L R U
    
    //Going Down-- i+1 , j 
    // Check if in range,  If not visted,  element val is non zero 
    
    if(isrange(i+1,j,n)&& visited[i+1][j]==0 && arr[i+1][j]!=0)
    {
        solve(visited,ans,arr,n,curr,i+1,j);
    }
    
    // going left
    if(isrange(i,j-1,n)&& visited[i][j-1]==0 && arr[i][j-1]!=0)
    {
        solve(visited,ans,arr,n,curr,i,j-1);
    }
    
    //Going Right
    if(isrange(i,j+1,n)&& visited[i][j+1]==0 && arr[i][j+1]!=0)
    {
        solve(visited,ans,arr,n,curr,i,j+1);
    }
    
    //Going Up
    if(isrange(i-1,j,n)&& visited[i-1][j]==0 && arr[i-1][j]!=0)
    {
        solve(visited,ans,arr,n,curr,i-1,j);
    }
    
    //backtrack
    curr[i*n+ j]=0;
    visited[i][j]=0;
    
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &arr, int n){
  // Write your code here.
    vector<vector<int>>ans;
    if(arr[n-1][n-1]==0) return ans;
    vector<int>curr(n*n,0);
    curr[(n*n)-1]=1;
    vector<vector<int>>visited(n,vector<int>(n,0));
    solve(visited,ans,arr,n,curr,0,0);
    return ans;
    
        
}

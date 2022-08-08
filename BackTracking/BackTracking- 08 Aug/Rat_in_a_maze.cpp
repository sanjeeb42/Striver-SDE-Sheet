class Solution{
    public:
    
    
    void solve(string s,vector<string>&ans,vector<vector<int>>&grid,int i,int j,vector<vector<int>>&visited){
        int n=grid.size();
  
        if(i==n-1 && j==n-1)
        {
            if(grid[i][j]!=0){
            ans.push_back(s);
            }
            return;
        }
        if(i>=n or i<0 or j>=n or j<0)return;
        if(grid[i][j]==0) return;
        if(visited[i][j])return;
        visited[i][j]=1;
        
        
        solve(s+'U',ans,grid,i-1,j,visited);
        solve(s+'R',ans,grid,i,j+1,visited);
        solve(s+'D',ans,grid,i+1,j,visited);
        solve(s+'L',ans,grid,i,j-1,visited);
        
        visited[i][j]=0;
        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        vector<vector<int>>visited(n+1,vector<int>(n+1,0));
        
        vector<string>ans;
        string s="";
        solve(s,ans,m,0,0,visited);
        
        return ans;
    }
};

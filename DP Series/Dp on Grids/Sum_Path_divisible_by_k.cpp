class Solution {
public:
    int num(vector<vector<int>>& grid, int &k,int i,int j,int sum,vector<vector<vector<int>>> &dp){

    if(i<0 || j<0)
        return 0;

    if(i==0 && j==0){
        
        if((sum+grid[i][j])%k==0)
            return 1;
        else
            return 0;
    }
       if(dp[i][j][sum]!=-1 ) {

       return dp[i][j][sum];
   } 
  
    int l=num(grid,k,i-1,j,(sum+grid[i][j])%k,dp);
    int r=num(grid,k,i,j-1,(sum+grid[i][j])%k,dp);
    // cout<<i<<" "<<j<<" "<<l<<" "<<r<<"\n ";

    return dp[i][j][sum]=(l+r)%1000000007;
}
int numberOfPaths(vector<vector<int>>& grid, int k) {
    vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>> (grid[0].size(),vector<int>(k, -1)));
    return num(grid,k,grid.size()-1,grid[0].size()-1,0,dp);
}
};

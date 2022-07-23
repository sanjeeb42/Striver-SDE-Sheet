int solve(vector<vector<vector<int>>>&dp,int row,int pos1,int pos2,vector<vector<int>>&grid){
    
    if(row>=grid.size())return 0;
    if(pos1<0 or pos1>=grid[0].size())return 0;
    if(pos2<0 or pos2>=grid[0].size())return 0;
    // recursive case
    
    if(dp[row][pos1][pos2]!=-1)return dp[row][pos1][pos2];
    int ans=grid[row][pos1];
    
    if(pos1!=pos2){
        ans+=grid[row][pos2];
    }
    int tmp=0;
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            tmp=max(tmp,solve(dp,row+1,pos1+i,pos2+j,grid));
        }
    }    
    ans+=tmp;    
    return dp[row][pos1][pos2]=ans;   
}


int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    //changing parameters are row,pos1,pos2;
    
    vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return solve(dp,0,0,c-1,grid);
}

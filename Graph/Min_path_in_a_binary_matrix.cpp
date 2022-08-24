class Solution {
public:
    
    int dx[8]={-1,-1,-1,0,0,1,1,1};
    int dy[8]={-1,0,1,-1,1,-1,0,1};
    
    
    bool isValid(int i,int j,vector<vector<int>>&grid){
        int n=grid.size();
        
        if(i<0 or j<0 or i>=n or j>=n or grid[i][j]==1 or grid[i][j]==-1){
            return false;
        }
        
        return true;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n=grid.size();
        
        if(grid[0][0]==1 or grid[n-1][n-1]==1)return -1;
        if(n==1)return 1;
        
        //Do Bfs
        
        queue<vector<int>>q;
        q.push({0,0,1});
        grid[0][0]=-1;
        
        int ans=INT_MAX;
        while(q.size()>0)
        {
            
            
            auto front=q.front();
            q.pop();
            int x=front[0],y=front[1],distance=front[2];
            
            if(x==n-1 and y==n-1){
                ans=min(ans,distance);
            }
            
            for(int k=0;k<8;k++)
            {
                int newx=x+dx[k];
                int newy=y+dy[k];
                if(isValid(newx,newy,grid)){
                    q.push({newx,newy,distance+1});
                    grid[newx][newy]=-1;
                }
            }
            
        }
        
        if(ans>=1e5){
            ans=-1;
        }
        return ans;
    }
};

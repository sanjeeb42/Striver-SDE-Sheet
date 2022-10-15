//https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1

class Solution {
  public:
  
    int dx[8]={-1,0,0,1};
    int dy[8]={0,1,-1,0};
    
    bool isSafe(int x,int y,int n,int m){
        if(x<0 or x>=n or y<0 or y>=m)return false;
        return true;
    }
    
    int solve(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
        {
            // xcordinate, ycordinate , distance
              queue<pair<pair<int,int>,int>>q;
              
              int n=grid.size(), m=grid[0].size();
              q.push({{source.first,source.second},0});
              
              while(q.size()>0)
              {
                  auto front=q.front();
                  q.pop();
                  int xcordinate=front.first.first, ycordinate=front.first.second;
                  int distance=front.second;
                  
                  if(xcordinate==destination.first && ycordinate==destination.second)return distance;
                  
                  for(int i=0;i<4;i++)
                  {
                     
                      if(isSafe(xcordinate+dx[i],ycordinate+dy[i],n,m) && grid[xcordinate+dx[i]][ycordinate+dy[i]]==1)
                      {
                          q.push({{xcordinate+dx[i],ycordinate+dy[i]},distance+1});
                          grid[xcordinate+dx[i]][ycordinate+dy[i]]=0;
                      }
                  }
              }
              
              return -1;
        }
    
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        return solve(grid,source,destination);
        
    }

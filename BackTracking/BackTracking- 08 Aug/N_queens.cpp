class Solution {
public:
    
    
bool isSafe(int row, int col, vector<string> &board)
{
  // Check same row- Linear

  int n=board.size();
  for (int i = 0; i < col; i++)
  {
    if (board[row][i] == 'Q')
    {
      return false;
    }
  }

  // Check Diagonally
    
 // Checking Upper Diagonal
 int i = row ;
  for (int j= col; j >= 0 && i>=0; j--)
  {
    if (board[i--][j] == 'Q')
      return false;
  }
    
  // Lower Diagonal
   i = row ;
  for (int j = col; j >= 0 && i<n; j--)
  {

    if (board[i++][j] == 'Q')
      return false;
  }
  return true;
}
    
    void solve(int index,vector<vector<string>>&ans,vector<string>&board)
    {
        int n=board.size();
        if(index==n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int i=0;i<n;i++)
        {           
               
                if(isSafe(i,index,board))
                {
                     board[i][index]='Q';
                     solve(index+1,ans,board);
                     board[i][index]='.'; 
                }
                  
        }
            
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        string s="";
        for(int i=0;i<n;i++){
            s.push_back('.');
        }
        vector<string>board(n,s);
        
        vector<vector<string>>ans;
        solve(0,ans,board);
        
        return ans;
        
    }
};

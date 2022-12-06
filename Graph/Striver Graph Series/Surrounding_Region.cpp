class Solution
{
    public:
        vector<int> dx = { -1,
            0,
            0,
            1
        };
    vector<int> dy = { 0,
        -1,
        1,
        0
    };

    bool issafe(int i, int j, int n, int m)
    {
        if (i < 0 or i >= n or j < 0 or j >= m) return false;
        return true;
    }
    void dfs(vector<vector < char>> &board, int i, int j,char ch)
    {
       	//Visited Means 'U' or 'N'

        int n = board.size(), m = board[0].size();

        //Not Possible Then ch=# else ch=X
        board[i][j]=ch;
        for (int k = 0; k < 4; k++)
        {
            int newx = i + dx[k];
            int newy = j + dy[k];

            if (issafe(newx, newy, n, m) && board[newx][newy] == 'O')
            {
                dfs(board, newx, newy,ch);
            }
        }
    }
    
    
    void solve(vector<vector < char>> &board)
    {
       	//Basically Find an island
       	//we will try to go for dfs with a visited array

        int n = board.size(), m = board[0].size();
       	//TO update = 'U' To Notupdate='N';
               
        //First move across the boundary and 
        //update all that connected to it by Not Possible
        
        char ch='#';
        for(int i=0;i<n;i++){
           //Checking for 1st and last column
            if(board[i][0]=='O')dfs(board,i,0,ch);
            if(board[i][m-1]=='O')dfs(board,i,m-1,ch);
        }
        
        for(int j=0;j<m;j++){
            //Checking for First and Last row
            if(board[0][j]=='O')dfs(board,0,j,ch);
            if(board[n-1][j]=='O')dfs(board,n-1,j,ch);
        }
      
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='#')board[i][j]='O';
                else if(board[i][j]=='O')board[i][j]='X';
            }
        }
        
    }
};

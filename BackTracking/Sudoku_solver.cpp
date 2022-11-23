class Solution
{
    public:
        bool issafe(vector<vector < char>> &board, int i, int j)
        {
            char val = board[i][j];
            board[i][j] = '.';
            int startrow = (i / 3) *3;
            int startcol = (j / 3) *3;

            for (int col = 0; col < 9; col++)
            {

                if (board[i][col] == val) return false;
            }

            for (int row = 0; row < 9; row++)
            {

                if (board[row][j] == val) return false;
            }

            for (int k = startrow; k < startrow + 3; k++)
            {
                for (int l = startcol; l < startcol + 3; l++)
                {

                    if (board[k][l] == val) return false;
                }
            }
            board[i][j] = val;
            return true;
        }

    bool solve(vector<vector < char>> &board)
    {

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    for (int k = '1'; k <= '9'; k++)
                    {
                        board[i][j] = k;
                        if (issafe(board, i, j) && solve(board)) return true;
                        else board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector < char>> &board)
    {
        solve(board);
    }
};

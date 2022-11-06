//Not verfified--> but hopefully correct


class Solution
{
    public:
        bool issafe(int i, int j, int n, int m)
        {
            if (i < 0 or i >= n or j < 0 or j >= m) return false;
            return true;
        }

    int solve(vector<vector<vector< int >>> &dp, vector< vector< char>> &board, string &words, int i, int j, int index)
    {
       	// cout<<"Calling for index: "<<index<<endl;
        int n = board.size(), m = board[0].size();
        if (index == words.size()) return 1;
        if (issafe(i, j, n, m) == false) return 0;
        if (dp[i][j][index] != -1) return dp[i][j][index];
       	//Else try every option
        int ans = 0;
        if (board[i][j] == words[index])
        {

            char tmp = board[i][j];
            board[i][j] = 'A';
            ans = solve(dp, board, words, i, j + 1, index + 1) or solve(dp, board, words, i + 1, j, index + 1)
            or solve(dp, board, words, i - 1, j, index + 1) or solve(dp, board, words, i, j - 1, index + 1);
            board[i][j] = tmp;
        }
        return dp[i][j][index] = ans;
    }
    vector<string> findWords(vector<vector < char>> &board, vector< string > &words)
    {
        vector<string> ans;
        int n = board.size(), m = board[0].size();
        for (int k = 0; k < words.size(); k++)
        {

            bool found = false;
            for (int i = 0; i < n; i++)
            {
                if (found) break;
                for (int j = 0; j < m; j++)
                {

                    if (found) break;
                    if (board[i][j] == words[k][0])
                    {
                        vector<vector<vector< int>>> dp(n + 1, vector<vector < int>> (m + 1, vector<int> (words[k].size() + 1, -1)));
                        if (solve(dp, board, words[k], i, j, 0) == 1)
                        {
                            ans.push_back(words[k]);
                            found = true;
                        }
                    }
                }
            }
        }

        return ans;
    }
};

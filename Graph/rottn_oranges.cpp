class Solution
{
    public:

        vector<int> dx = { -1,
            0,
            0,
            1
        };
    vector<int> dy = { 0,
        1,
        -1,
        0
    };

    bool issafe(int i, int j, int n, int m)
    {
        if (i < 0 or j < 0 or i >= n or j >= m) return false;
        return true;
    }

    int orangesRotting(vector<vector < int>> &grid)
    {
       	//Question of BFS
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size();

       	//Initialise
        int ones = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({ i,
                        j });
                    grid[i][j] = -1;
                }
                else if (grid[i][j] == 1) ones++;
            }
        }

       	//Time to do bfs now
        int ans = 0;
        while (q.size() > 0)
        {
            int size=q.size();
            for (int i = 0; i < size; i++)
            {
                auto front = q.front();
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int newx = front.first + dx[k];
                    int newy = front.second + dy[k];

                    if (issafe(newx, newy, n, m) && grid[newx][newy] == 1)
                    {
                        q.push({ newx,
                            newy });
                        grid[newx][newy] = -1;
                        ones--;
                    }
                }
            }
            if (q.size() > 0) ans++;
        }

        if (ones != 0) ans = -1;
        return ans;
    }
};

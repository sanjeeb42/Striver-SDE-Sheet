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
    vector<vector < int>> updateMatrix(vector<vector < int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        vector<vector < int>> ans(n, vector<int> (m, -1));

        queue<pair<int, int>> q;	// i,j,distance
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    ans[i][j] = 0;
                    q.push({ i,
                        j });
                }
            }
        }

       	//Now time to try bfs 
       	// If we encounter 1 we will update the value
        int level = 0;
        while (q.size() > 0)
        {
            auto front = q.front();
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int newx = front.first + dx[k];
                int newy = front.second + dy[k];

                if (issafe(newx, newy, n, m) && ans[newx][newy] == -1)
                {
                    ans[newx][newy] = ans[front.first][front.second] + 1;
                    q.push({ newx,
                        newy });
                }
            }
        }

        return ans;
    }
};

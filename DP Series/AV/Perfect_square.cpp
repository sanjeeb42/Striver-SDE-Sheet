  int solve(int n, vector<int> &dp)
        {
            if (n == 0) return 0;

            if (dp[n] != -1) return dp[n];
            int j = sqrt(n);
            int tmp = n;
            for (int i = 1; i <= j; i++)
            {
                tmp = min(tmp, 1 + solve(n - i *i, dp));
            }
            return dp[n] = tmp;
        }
    int numSquares(int n)
    {
        vector<int> dp(n + 1, 0);

        for (int k =1; k <= n; k++)
        {
            int j = sqrt(k);
            int tmp = k;
            for (int i = 1; i <= j; i++)
            {
                tmp = min(tmp, 1 + dp[k - i *i]);
            }
            dp[k] = tmp;
        }
        return dp[n];
    }

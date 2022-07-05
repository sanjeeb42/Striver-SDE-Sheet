class Solution
{
    public:
        int minDistance(string a, string b)
        {
            int m = a.length(), n = b.length();
           
            vector<vector < int>> dp(m + 1, vector<int> (n + 1, 0));

           	// Find LCS

            for (int i = 1; i <= m; i++)
            {
                for (int j = 1; j <= n; j++)
                {

                   	// Case 1. If a[i-1]==b[j-1]

                    if (a[i - 1] == b[j - 1]) {
                        dp[i][j]=1+dp[i-1][j-1];
                    }
                    else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
            
            
            int LCS_length=dp[m][n];
            
            return m+n- 2*LCS_length;
        }
};

class Solution
{
    public:
        int maxCoins(vector<int> &arr)
        {

            int n = arr.size();

            vector<vector < int>> dp(n + 1, vector<int> (n + 1, 0));

           	//Traverse diagonally --> Gap method
            for (int gap = 0; gap < n; gap++)
            {
                int i = 0;
                for (int j = gap; j < n; j++, i++)
                {

                    int tmpans = 0;
                    int prev = 1, next = 1;
                    if (i != 0) prev = arr[i - 1];
                    if (j != n - 1) next = arr[j + 1];
                    for (int k = i; k <= j; k++)
                    {
                        int currans = prev *arr[k] *next;
                        int left = 0,right=0;
                        if (k > i)
                        {
                            left = dp[i][k - 1];
                        }
                        if (k < j)
                        {
                            right = dp[k + 1][j];
                        }

                        currans = currans + right + left;
                        
                        tmpans=max(tmpans,currans);
                    }
                    dp[i][j]=tmpans;
                }
            }
            
            return dp[0][n-1];
        }
};

class Solution
{
    public:
        int numSubmatrixSumTarget(vector<vector < int>> &matrix, int target)
        {
            int m = matrix.size(), n = matrix[0].size();
            map<int, int> mp;
            for (int row = 0; row < m; row++)
            {
                for (int col = 1; col < n; col++)
                {
                	// calculating prefix sum;
                    matrix[row][col] += matrix[row][col - 1];
                }
            }

            int count = 0;

            for (int c1 = 0; c1 < n; c1++)
            {
                for (int c2 = c1; c2 < n; c2++)
                {

                    mp.clear();	// **IMPORTANT as we are changing pair of coloums each time so new values need to be assigned.
                    mp[0] = 1;
                    int sum = 0;

                    for (int row = 0; row < m; row++)
                    {
                        sum += matrix[row][c2] - (c1 > 0 ? matrix[row][c1 - 1] : 0);	// if previous coloumn value is less than 0 then add 0.
                        if (mp.count(sum - target)) count += mp[sum - target];

                        mp[sum]++;
                    }
                }
            }

            return count;
        }
};

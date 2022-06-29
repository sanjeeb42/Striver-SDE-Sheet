#include <bits/stdc++.h>

class Solution
{
    public:
        vector<vector < int>> kClosest(vector<vector < int>> &points, int k)
        {
            priority_queue<pair < long long int, vector< int>>> pq;
            int n = points.size();
            for (int i = 0; i < n; i++)
            {
                long long dist = points[i][0] *points[i][0] + points[i][1] *points[i][1];
                pq.push({ dist,
                    {
                        points[i][0],
                        points[i][1]
                    } });

                if (pq.size() > k)
                {
                    pq.pop();
                }
            }
            vector<vector < int>> ans;
            while (pq.size() > 0)
            {
                ans.push_back(pq.top().second);
                pq.pop();
            }

            return ans;
        }
};

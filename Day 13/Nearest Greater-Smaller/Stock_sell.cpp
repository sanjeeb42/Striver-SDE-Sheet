#include <bits/stdc++.h>

vector<int> findSpans(vector<int> &arr)
{
   	// Write your code here.

    stack<pair<int, int>> st;
    vector<int> ans;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
       	//   int len=1;
        if (st.empty())
        {
            ans.push_back(1);
            st.push({ arr[i],
                i });
        }
        else if (st.top().first > arr[i])
        {
            ans.push_back(1);
            st.push({ arr[i],
                i });
        }
        else
        {
            while (st.size() > 0 and st.top().first <= arr[i])
            {
               	//   len+=st.top().second;
                st.pop();
            }

            if (st.empty())
            {
                ans.push_back(i + 1);
                st.push({ arr[i],
                    i });
            }
            else
            {
                ans.push_back(i - st.top().second);
                st.push({ arr[i],
                    i });
            }
        }
    }

    return ans;
}

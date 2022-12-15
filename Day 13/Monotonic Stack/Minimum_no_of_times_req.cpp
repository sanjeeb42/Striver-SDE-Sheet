https://leetcode.com/problems/steps-to-make-array-non-decreasing/


class Solution
{
    public:
        int totalSteps(vector<int> &nums)
        {
            stack<pair<int, int>> st;
            int n = nums.size();
            st.push({ nums[n - 1],
                0 });

            int ans = 0;

            for (int i = n - 2; i >= 0; i--)
            {
                int val = nums[i];

                auto topval = st.top().first;

                if (topval >= val)
                {
                 //   cout << "Entred Case 1:  " << nums[i] << endl;

                    st.push({ val,
                        0 });
                }
                else
                {
                  //  cout << "Entred Case 2:  " << nums[i] << endl;

                    int times = 0;
                    while (st.size() > 0 && st.top().first < val)
                    {
                        times = max(times + 1, st.top().second);
                      //  cout<<times<<endl;
                        st.pop();
                    }
                    st.push({ val,
                        times });
                }
            }

            while (st.size() > 0)
            {
                int times = st.top().second;
                ans = max(ans, times);
                st.pop();
            }

            return ans;
        }
};

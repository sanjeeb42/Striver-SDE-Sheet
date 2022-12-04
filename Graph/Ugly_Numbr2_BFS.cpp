https://leetcode.com/problems/ugly-number-ii/


#define ll long long
class Solution
{
    public:
        int nthUglyNumber(int n)
        {
            set<ll> st;
            vector<ll> ans;
            vector<ll> nums = { 1,
                2,
                3,
                4,
                5,
                6,
                8,
                9
            };
            for (ll i = 0; i < nums.size(); i++)
            {
                st.insert(nums[i]);
            }

            while (ans.size() < n-1)
            {
                auto front = *st.begin();
                ans.push_back(front);

                st.erase(st.begin());
                st.insert(front *2);
                st.insert(front *3);
                st.insert(front *5);
            }
            return *st.begin();
        }
};

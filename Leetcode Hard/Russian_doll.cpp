https://leetcode.com/problems/russian-doll-envelopes/

class Solution
{
    public:

       	//Sort in increasing order of width and Decreasing order of height
       static bool cmp(vector<int> &a, vector<int> &b)
        {
            if (a[0] == b[0])
            {
               	//Sort in decreasing order of heights
                return a[1] > b[1];
            }
            return a[0] < b[0];
        }

//     int lis(vector<vector < int>> &dp, vector< vector< int>> &envelopes, int prev, int index)
//     {

//         int n = envelopes.size();

//         if (index >= n) return 0;
//         if (dp[prev + 1][index] != -1) return dp[prev + 1][index];

//         int take = 0, not_take = 0;
//         if (prev == -1 or(envelopes[prev][0] < envelopes[index][0] && envelopes[prev][1] < envelopes[index][1]))
//         {
//             take = 1 + lis(dp, envelopes, index, index + 1);
//         }
//         not_take = lis(dp, envelopes, prev, index + 1);

//         return dp[prev + 1][index] = max(take, not_take);
//     }
    
    
    int sort_optimal(vector<vector<int>>&envelopes){
        
        //Pahele ek vector bnao of height and do lis using dp+binary serach
        
        vector<int>arr;
        for(auto it: envelopes){
            arr.push_back(it[1]);
        }
        
        
        vector<int>ans;
        ans.push_back(arr[0]);
        
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]>ans.back()){
                ans.push_back(arr[i]);
            }
            
            //else fit the current element in its correct place
            else{
                int index=lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
                ans[index]=arr[i];      
            }
        }
        return ans.size();
    }
    int maxEnvelopes(vector<vector < int>> &envelopes)
    {
       	//It is of LIS
        int prev = -1;
        sort(envelopes.begin(), envelopes.end(), cmp);
        int n = envelopes.size();
        // int ans = lis(dp, envelopes, prev, 0);
        
        int ans=sort_optimal(envelopes);
        return ans;
    }
};

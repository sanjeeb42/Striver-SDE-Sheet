//https://leetcode.com/problems/continuous-subarray-sum/


//Intuition
We need a subarray say from i to j such that sum of all elements is divisible by k.

sum_j means prefix sum from 0 to j

sum_i means prefix sum from 0 to i

 => (sum_j - sum_i) % k = 0
 => sum_j % k - sum % k = 0
 => sum_j % k = sum_i % k    <Relation derived !!!>
Thus for some prefix_sum(0,j) , we need to check if there exist some prefix_sum(0,i) such that both are equal.

If yes then return true.
Otherwise check for some other j


class Solution
{
    public:
        bool checkSubarraySum(vector<int> &nums, int k)
        {
           	//PrefixSum (0,j)--> Prefix sum from 0 to J
           	//PrefixSum (0,i)--> Prefix sum from 0 to i

           	//prefixSum(j,i)--> prefixsum(0,j)-Prefixsum(0,i)
           	//If Prefixsum(j,i) is divisible by k then
           	//Prefixum(0,j)-Prefixsum(0,i))%k==0

           	//Final Solution is: -
           	//Prefixsum(0,j)%k==Prefixsum(0,i)%k

            unordered_map<int, int> mp;
            int prefixsum = 0;
            int n=nums.size();
            for (int i = 0; i < n; i++)
            {
                prefixsum = (prefixsum + nums[i]) % k;
                
                if(prefixsum==0 && i!=0)return true;
                if (mp.find(prefixsum) != mp.end())
                {
                   	//Means There exist a possible solution
                    int index = mp[prefixsum];
                    if (i - index > 1)
                    {
                        return true;
                    }
                }
                else
                {
                   	//Not Found Case
                    mp[prefixsum] = i;
                }
            }

            return false;
        }
};

//https://leetcode.com/problems/maximum-sum-circular-subarray/

class Solution
{
    public:

        int Kadane_Max(vector<int> &nums)
        {
            int n = nums.size();

            int currsum = 0;
            int max_sum = nums[0];
            for (int i = 0; i < n; i++)
            {
                currsum += nums[i];
                max_sum = max(currsum, max_sum);
                if(currsum<0)
                {
                   currsum=0;
                }
            }
            return max_sum;
        }
    
    int Kadane_Min(vector<int>&nums){
        int n=nums.size();
        
        int currsum=0;
        int min_sum=nums[0];
        
        for(int i=0;i<n;i++){
            currsum+=nums[i];
            min_sum=min(min_sum,currsum);
            if(currsum>0){
                currsum=0;
            }    
        }
        return min_sum;
    }
    int maxSubarraySumCircular(vector<int> &nums)
    {

        int n = nums.size();

        int max_sum=Kadane_Max(nums);
        int min_sum=Kadane_Min(nums);
        
       // cout<<"max_sum: "<<max_sum<<" and min_sum: "<<min_sum<<endl;
        
        int total_sum=accumulate(nums.begin(),nums.end(),0);
        
        int circular_sum=total_sum-min_sum;
        if(max_sum<0)return max_sum;
        return max(max_sum,circular_sum);
    }
};

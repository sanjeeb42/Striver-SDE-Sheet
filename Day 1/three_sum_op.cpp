class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        //Sorted Now do binary search
        int n=nums.size();
        vector<vector<int>>ans;
       
        for(int i=0;i<n-2;i++){
            int target=0-nums[i];
            
            //Find remaining two elements from the given array
            int low=i+1, high=n-1;
            while(low<high)
            {
                int curr_ans=nums[low]+nums[high];
                if(curr_ans==target)
                {
                  ans.push_back({nums[i],nums[low],nums[high]});
                  low++,high--;
                  while(low<= n-1&& nums[low]==nums[low-1])low++;
                  while( high>=0 && nums[high]==nums[high+1])high--;
                }
                else if(curr_ans<target){
                    low++;
                }
                else high--;
            }
            while(i<n-1 && nums[i+1]==nums[i])i++;
        }
        
        return ans;
    }
};

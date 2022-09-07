class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        vector<int>leftmin(n,INT_MAX);
        leftmin[0]=nums[0];
        
        //Finding Left in -> So 1 3 pattern found
        for(int i=1;i<n;i++){
            leftmin[i]=min(leftmin[i-1],nums[i]);
        }
        
//         for(auto it:leftmin){
//             cout<<it<<" ";
//         }
//         cout<<endl;
        //Now Let's Find 3 2 pattern ie find(3,1) exclusive
        
        multiset<int>arr;
        arr.insert(nums[n-1]);
        
        for(int i=n-2;i>0;i--){
            arr.insert(nums[i]);
            // sort(arr.begin(),arr.end());
            if(leftmin[i]<nums[i]){
                //Now find 3-2 pattern
                auto index=arr.upper_bound(leftmin[i]);
                if(index==arr.end())continue;
                else if(*index<nums[i]){
                   // cout<<i<<endl;
                    return true;
                }
            }
        }
        
        return false;
    }
};

//Logic - https://leetcode.com/problems/count-subarrays-with-median-k/discuss/2851940/Balance

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        //
        int balance=0;
        int median_index=find(nums.begin(),nums.end(),k)-nums.begin();
        
        int ans=0;
        mp[0]=1;
        
        //We will go right and First Form the balance array
        for(int i=median_index+1;i<n;i++){
            balance+=(nums[i]>k?1:-1);
            mp[balance]++;
        }
        
       
        balance=0;
        //Now we will go left and Find ans
        for(int i=median_index;i>=0;i--){
            balance+=(nums[i]>k?1:-1);
            if(nums[i]==k)balance++;
            int index=-1* balance;
            ans+=(mp[index]+mp[index+1]);
            cout<<ans<<endl;
        }
        
        return ans;
    }
};

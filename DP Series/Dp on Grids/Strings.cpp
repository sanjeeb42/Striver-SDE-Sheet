class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n,1),right(n,1);
        
        for(int i=1;i<n;i++){
            int ans=1;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    ans=max(ans,left[j]+1);
                }
                
            }
            left[i]=ans;
        }
        
        for(int i=n-2;i>=0;i--){
            int ans=1;
            for(int j=n-1;j>i;j--){
                if(nums[j]<nums[i]){
                    ans=max(ans,right[j]+1);
                }
                
            }
            right[i]=ans;
        }
        
        int fans=1;
        for(int i=0;i<n;i++){
            if(left[i]==1 or right[i]==1)continue;
            fans=max(fans,right[i]+left[i]-1);
        }
        
        return n-fans;
    }
};

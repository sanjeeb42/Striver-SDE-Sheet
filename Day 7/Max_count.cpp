//Code Studio

int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    
    int ans=0,kk=k,left=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            
        }
        else if(arr[i]==0)
        {
            kk--;
            if(kk<0)
            {
                while(left<i && kk<0)
                {
                     if(arr[left]==0)
                     {
                         kk++;
                     }
                    left++;
                }
            }
        }
        ans=max(ans,i-left+1);
    }   
    return ans;
}


//Leetcode


int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1){
                cnt++;
            }
            else cnt=0;
            
            ans=max(ans,cnt);
        }
        
        return ans;
    }

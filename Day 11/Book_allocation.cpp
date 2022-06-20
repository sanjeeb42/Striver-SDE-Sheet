class Solution {
public:
    bool isallocnpossible(vector<int>&arr,int m, int limit){
        int times=1;
        int n=arr.size();
        int curr_sum=0;
        for(int i=0;i<n;i++){
            if(arr[i]>limit)return false;
            if(curr_sum+arr[i]<=limit){
                curr_sum+=arr[i];
            }
            else{
                times++;
                curr_sum=arr[i];
            }
        }
        
     //  cout<<"Times: "<<times<<endl;
        
        bool ans=times<=m?true:false;
     //   cout<<ans<<endl;
        return ans;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int mini=nums[0];
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            mini=max(mini,nums[i]);
        }
        
        int low=mini, high=sum;
        int ans;
        while(low<=high){
            
            int mid=low+(high-low)/2;
          //  cout<<"Low: "<<low<<" and mid: "<<mid<<" and high: "<<high<<endl;
            
            if(isallocnpossible(nums,m,mid)==true){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
            
          //  cout<<"Low: "<<low<<" and high: "<<high<<endl;
        }
        
        return ans;
    }
};

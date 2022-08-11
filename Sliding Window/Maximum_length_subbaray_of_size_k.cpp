 int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        // Complete the function
        unordered_map<int,int>mp;
        int sum=0;
        mp[0]=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(mp.find(sum)==mp.end()){
            mp[sum]=i+1;
            }
            
            if(mp.find(sum-k)!=mp.end())
            {
                ans=max(ans,abs(i+1-mp[sum-k]));
            }
        }
        
        return ans;
    } 

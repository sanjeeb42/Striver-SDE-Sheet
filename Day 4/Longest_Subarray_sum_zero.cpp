// Efficient approach using Unordered map

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
   int n=arr.size();
   vector<int>prefixSum(n);
    prefixSum[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        prefixSum[i]=prefixSum[i-1]+arr[i];      
    }
    
    unordered_map<int,int>mp;
    mp[0]=0;
    for(int i=0;i<n;i++)
    {
       if(mp.find(prefixSum[i])==mp.end())
       {
         mp[prefixSum[i]]=i+1;
       }    
    }
   
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int prev=mp[prefixSum[i]];
        ans=max(ans,i - prev +1);
    }
    
    return ans;
}


// Naive

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
    
    int ans=0;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        int sum=arr[i];
        if(sum==0){
            ans=max(ans,1);
        }
        for(int j=i+1;j<n;j++)
        {
            sum+=arr[j];
           // cout<<sum<<" ";
            if(sum==0)
            {
                ans=max(ans,j-i+1);
            }
        }
    }
    return ans;

}

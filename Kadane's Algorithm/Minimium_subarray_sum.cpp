int smallestSumSubarray(vector<int>& arr){
      //Code here
      int n=arr.size();
      int ans=INT_MAX;
      int curr_sum=0;
      for(int i=0;i<n;i++)
      {
          
          curr_sum+=arr[i];
          
          ans=min(ans,curr_sum);
          if(curr_sum>0)
          {
              curr_sum=0;
          }
      }
      
      return ans;
  }

https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1

int solve(vector<vector<int>>&dp,int arr[],int n,int index,int currsum,int maxsum)
  {
      if(index==n)
      {
          int p1=maxsum-currsum;
          int p2=currsum;
          return abs(p1-p2);
      }
      
      if(dp[index][currsum]!=-1)return dp[index][currsum];
      //Take or nottake
      int take=solve(dp,arr,n,index+1,currsum+arr[index],maxsum);
      int nottake=solve(dp,arr,n,index+1,currsum,maxsum);
      
      return dp[index][currsum]=min(take,nottake);
      
  }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    
	    int sum=accumulate(arr,arr+n,0);
	    
	    //Take or not take
	    int currsum=0;
	    vector<vector<int>>dp(n+1,vector<int>(sum,-1));
	    int ans=solve(dp,arr,n,0,currsum,sum);
	    return ans;
	} 

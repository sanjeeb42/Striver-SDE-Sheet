//https://practice.geeksforgeeks.org/problems/array-removals/1

2 solution- One using Dp and other using binary serach


class Solution{
    public:
    
    int ans=INT_MAX;
    int solve(vector<vector<int>>&dp,vector<int>&arr,int k,int start,int end){
        int n=arr.size();
        int diff=arr[end]-arr[start];
        if(diff<=k)
        {
            ans=min(ans,n-(end-start+1));
            return dp[start][end]=ans;
        }
        if(start>=end)return dp[start][end]=ans;
        if(dp[start][end]!=-1)return dp[start][end];
        solve(dp,arr,k,start+1,end);
        solve(dp,arr,k,start,end-1);
        
        return dp[start][end]=ans;
    }
    int removals(vector<int>& arr, int k){
        //Code here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int start=0, end=n-1;
       // Remove x elements from front and y elements from back
       //At each step we can either remove first or last element
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(dp,arr,k,start,end);
        //return ans;
    }
};


//Binary Search

 public:
    int removals(vector<int>& arr, int k){
        //Code here
        int n=arr.size();
        sort(arr.begin(),arr.end());

        int ans=n;
        for(int i=0;i<n;i++)
        {
            int target=arr[i]+k;
            auto it=lower_bound(arr.begin()+i,arr.end(),target);
            int index=it-arr.begin();
            ans=min(ans,n-index+i);
        }
        return ans;
    }

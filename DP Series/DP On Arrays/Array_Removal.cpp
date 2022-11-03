//https://practice.geeksforgeeks.org/problems/array-removals/1


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

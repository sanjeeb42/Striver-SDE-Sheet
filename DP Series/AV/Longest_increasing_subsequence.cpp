// Steps:
// 1. The idea is to replicate the input array to another array. (input arr = arr1, replicated arr = arr2)
// 2. Sort arr2 and remove duplicates
// 3. apply LCS to both arrays (arr1 and arr2)
// 4. return dp [ arr1.size() ] [ arr2.size() ], if it asks for the length of the LIS.




class Solution {
public:
    int lengthOfLIS(vector<int>&arr1) {
        vector<int> arr2=arr1;
        sort(arr2.begin(),arr2.end());
        auto it=unique(arr2.begin(),arr2.end());
        arr2.resize(distance(arr2.begin(),it));
        int m=arr1.size(), n=arr2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(arr1[i-1]==arr2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        
        return dp[m][n];
    }
};


#include<bits/stdc++.h>

int lcs(string a, string b)
{
	//Write your code here
   int m=a.length(), n=b.length(); 
   vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    return dp[m][n];
    
//     string ans="";
//     int i=n,j=n;
//     while(i>0 && j>0){
//         if(a[i-1]==b[j-1]){
//             ans.push_back(a[i-1]);
//             i--,j--;
//         }
//         else {
//             if(dp[i-1][j]>dp[i][j-1]){
//                 i--;
//             }
//             else j--;
//         }
//     }
//     reverse(ans.begin(),ans.end());
    
//     return ans;
}

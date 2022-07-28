class Solution{
public:
   long long int mod = 1e9+7;
   int factorial(int n, int r, int dp[1001][1001]){
       if(r==0||r==n) return 1;
       if(dp[n][r]!=0) return dp[n][r];
       dp[n][r]=(factorial (n-1,r,dp)%mod + factorial (n-1,r-1,dp)%mod)%mod;
       return dp[n][r]%mod;
       
   }
   int knots(int m, int n, int k){
       int dp[1001][1001];
     int a = factorial(m,k,dp);
     int b = factorial(n,k,dp);
     
     return (a%mod * b%mod)%mod;
   }
};

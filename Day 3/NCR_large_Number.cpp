int m=1e9+7;
  
  long long int factorial(int n,int r){
      
      //Initialise all
      vector<long long>dp(r+1,0);
      dp[0]=1;
      
      for(int i=1;i<=n;i++){
          for(int j=r;j>0;j--){
              dp[j]=(dp[j-1]+dp[j])%m;
          }
      }
      
      return dp[r];
      
  }
    long long int numberOfPaths(int m, int n){
        // code here
        
        return factorial(m+n-2,min(m,n)-1);
        
    }

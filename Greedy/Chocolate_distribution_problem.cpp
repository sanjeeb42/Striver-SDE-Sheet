class{ 

public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    
    sort(a.begin(),a.end());
    long long ans=INT_MAX;
    
    int j=m-1,i=0;
    while(j<n)
    {
        ans=min(ans,a[j]-a[i]);
        j++,i++;
    }
      return ans;
    
    } 
};

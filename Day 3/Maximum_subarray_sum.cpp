#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    
    long long ans=0;
    long long curr_sum=0;
    for(int i=0;i<n;i++)
    {
        curr_sum+=arr[i];
        if(curr_sum<0)
        {
            curr_sum=0;
        }
        ans=max(curr_sum,ans);

    }
    
    return ans;
    
    
}

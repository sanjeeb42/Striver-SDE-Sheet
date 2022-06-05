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



// Nice approach - Codestudio but Not efficient

/*  
    Time Complexity : O(N * log(N))
    Space Complexity : O(N)

    Where N is the length of array.
*/


long crossSum(int* arr, int low, int high, int mid) {

    if (low == high) {
        return arr[low];
    }

    long leftSubsum = 0;
    long currSum = 0;

    // maximum subarray sum by including elements on left of mid.
    for (int i = mid; i > low - 1; --i) {

        currSum += arr[i];
        leftSubsum = max(leftSubsum, currSum);

    }

    long rightSubsum = 0;
    currSum = 0;

    // maximum subarray sum by include elements on right of mid.
    for (int i = mid + 1; i < high + 1; ++i) {

        currSum += arr[i];
        rightSubsum = max(rightSubsum, currSum);

    }

    return leftSubsum + rightSubsum;
}

long maxSubarraySumHelper(int* arr, int low, int high) {
    // if there is only one element.
    if (low == high) {
        return arr[low];
    }

    int mid = (low + high) / 2;

    // left maximum subarray sum
    long leftSum = maxSubarraySumHelper(arr, low, mid);

    // right maximum subarray sum
    long rightSum = maxSubarraySumHelper(arr, mid + 1, high);

    // Maximum subarray sum such that the subarray crosses the midpoint.
    long crossS = crossSum(arr, low, high, mid);

    return max(max(leftSum, rightSum), crossS);
}


long maxSubarraySum(int* arr, int n) {

    return maxSubarraySumHelper(arr, 0, n - 1);
}

#include<bits/stdc++.h>
int count(int arr[], int x, int n)
{   
  /* get the index of first occurrence of x */
  int *low = lower_bound(arr, arr+n, x);
 
  // If element is not present, return 0
  if (low == (arr + n) || *low != x)
     return 0;
    
  /* Else get the index of last occurrence of x.
     Note that we  are only looking in the
     subarray after first occurrence */  
  int *high = upper_bound(low, arr+n, x);    
    
  /* return count */
  return high - low;
}

int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    
    sort(at,at+n);
    sort(dt,dt+n);   
    int maxi=1;
    int k=0;
    for(int j=0;j<=2359;j++)
    {
        //Bhai isko kam karo yaar
        //Kuch Binary search lgao 
        // warna count 0(n) to dikkt dega 
        k+=count(at,j,n); 
        maxi=max(maxi,k);
        k-=count(dt,j,n);                                             
    }
    
    return maxi;
}

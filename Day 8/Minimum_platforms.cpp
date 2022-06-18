//My approach -o(nlogn) time for traversing + 0(2nlogn) sort

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



// Efficent approach - O92nlogn) sort time+ O(n) traverse time

int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at,at+n);
    sort(dt,dt+n);
    
    int start1=1,start2=0;
    int ans=1;
    int platform_need=1;
    while(start1<n && start2<n){
        // If arrival time of new train is smaller than or equal the departaure timeof 
        //all the trains avialble on station, New platfrom needed
        
        if(at[start1]<=dt[start2]){
            platform_need++;
            start1++;
        }
        
        //departure time of any train standing on the station 
        //is smaller than the arrival time, Then it will first leave the platfrom .           //hence platform free
        else {
            platform_need--;
            start2++;
        }
        
        ans=max(ans,platform_need);
    }
    
    return ans;
}

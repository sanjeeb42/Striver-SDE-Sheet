#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
	// Write your code here.
    // Count of majority elemnt will be greater than n/2+ x
    
    
    int element=arr[0];
    int curr_count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==element){
            curr_count++;
        }
        else curr_count--;
        if(curr_count<=0)
        {
            element=arr[i];
            curr_count=1;
         }
    }
    
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==element){

        cnt++;
        }
    }
    if(cnt<=n/2)
    {
        element=-1;
    }
    
    
    return element;
}

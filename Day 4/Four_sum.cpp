//90% Pass

#include <bits/stdc++.h>

bool twosum(vector<int>arr,int low,int high,int target)
{

    while(low<high)
    {
        int curr=arr[low]+arr[high];
        if(curr<target){
            while(arr[low]==arr[low+1] and low<high)
            {
                low++;
            }
            low++;
            
        }
        
        else if(curr>target)
        {
             while(arr[high]==arr[high-1])
            {
                high--;
            }
            high--;

        }
        
        else 
        {
           // cout<<arr[low]<<" and "<<arr[high]<< " and "<<target <<endl;
           return true;
        }
    }
    return false;
}

string fourSum(vector<int> arr, int target, int n)
{
    // Write your code here.

    sort(arr.begin(),arr.end());
    for(int i=0;i<n-3;i++)
    {
        int first=arr[i];
        if(i>0 and arr[i]==arr[i-1]){
            continue;
        }
      
        for(int j=i+1;j<n-2;j++)
        {    
           
            if(arr[j]==arr[j-1]){
                continue;
            }
            int second=arr[j];
            //cout<<"Target is: "<<target-first-second<<endl;
            if(twosum(arr,j+1,n-1,target-first-second))
            {
                
                return "Yes";
            }
           
        }
    }
    return "No";
}



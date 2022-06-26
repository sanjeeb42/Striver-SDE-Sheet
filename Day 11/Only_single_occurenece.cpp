#include<bits/stdc++.h>

// int uniqueElement(vector<int> arr, int n)
// {
// 	// Write your code here
//     int xor_val=0;
//     for(int i=0;i<n;i++){
//         xor_val=xor_val xor arr[i];
//     }
//     return xor_val;
// }

// int uniqueElement(vector<int> arr, int n)
// {
//     int ans;
//     for(int i=0;i<n;i++){
//         if(arr[i]!=arr[i+1]){
//             ans=arr[i];
//             break;
//         }
//         i++;
//     }
//     return ans;
// }


int uniqueElement(vector<int>nums, int n)
{
//     int n=nums.size();
        int low=nums[0], high=nums[n-1];
        while(low<=high){
            int mid=low+(high-low)/2;
            
            int tmp_index=upper_bound(nums.begin(),nums.end(),mid)-nums.begin();
            if(tmp_index%2==0){
                low=mid+1;
            }
            else high=mid-1;
            
        }
        
        return low;
}



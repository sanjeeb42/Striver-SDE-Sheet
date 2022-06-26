#include<bits/stdc++.h>



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


// Binary Search 2

// The idea here is to use binary search and move left and right using the below observation.

// If mid is even, and arr[mid] == arr[mid + 1], then size of subarray [0...mid-1] (left side) is even (since the every element occurs twice), so left side does not contain the single occurrence element. Hence we need to check in [mid + 1, ..., N] subarray (right side of mid). Else we need to search for the required element on the left side.
// Example:
//  [1, 1, 2, 2, 3(mid), 3, 5, 7, 7]
// Here mid = 4.  Here subarray[0…3] doesn’t contain our unique number. So we need to check in the right side of the mid i.e. subarray [5… 8].
// If mid is odd, and arr[mid] == arr[mid - 1], then the size of subarray [0...mid - 2] (left side) is even (since every element occurs twice), so the left side does not contain the single occurrence element. Hence we need to check in subarray [mid + 1, ..., N] (right side of mid). Else we need to search for the required element on the left side.
// Example 
// [1, 1, 2, 2, 3, 3(mid), 5, 7, 7]
// Here mid = 5.  Here subarray[0…3] doesn’t contain our unique number. So we need to check in the right side of mid i.e. subarray [6… 8].

int uniqueElement(vector<int> arr, int n)
{
	int low = 0, high = n - 1, mid;

	// Do binary search
	while (low < high) {

		// Calculate mid
		mid = (low + high) / 2;

		// Update low and high
		if ((mid % 2 == 1 and arr[mid] == arr[mid - 1]) or (mid % 2 == 0 and arr[mid] == arr[mid + 1]))
		{
			low = mid + 1;
		}
		else
		{
			high = mid;
		}
	}

	return arr[low];
}


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






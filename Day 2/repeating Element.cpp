#include <bits/stdc++.h> 
int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
    // First- Sort the arrays and find the element
    // 2nd approach is to use two loops  Super naive
    // linked list cycle detection technique
    
    int slow=arr[arr[0]], fast=arr[arr[arr[0]]];
    while(slow!=fast )
    {
        slow=arr[slow];
        fast=arr[arr[fast]];
    }
    
    fast=arr[0];
    while(slow!=fast)
    {
        slow=arr[slow];
        fast=arr[fast];

    }
    return slow;  
}

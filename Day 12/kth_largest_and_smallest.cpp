#include<bits/stdc++.h>
#define insert push
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Write your code here.
    priority_queue<int>pq;
    for(auto it:arr){
        pq.insert(it);
    }
    vector<int>ans;
    int cnt=0;
    int smallest, largest;
    while(pq.empty()==false){
        cnt++;
        if(cnt==k){
            smallest=pq.top();
        }
        
        if(cnt==n-k+1){
            largest=pq.top();
        }
        
        pq.pop();
        
    }
    ans.push_back(largest);
    ans.push_back(smallest);
    
    return ans;
}


// using Quicksort

/*
    Time complexity: O(N)
    Space complexity: O(1)

    Where ‘N’ is the size of the given array.
*/

int partition(vector<int> &arr, int left, int right, int pivotIndex) 
{
    int pivotValue = arr[pivotIndex];
    
    // Bring pivot element at the end of range.
    swap(arr[pivotIndex], arr[right]); 

    int current = left;
    
    for(int i = left; i < right; i++) 
    {
        if(arr[i] < pivotValue) 
        {
            swap(arr[current], arr[i]);
            current++;
        }
    }
    swap(arr[right], arr[current]);
    
    return current;
}

int quickSelect(vector<int> &arr, int left, int right, int k) 
{
    if(left == right)
    {
        // Size of array is 1.
        return arr[left];
    }
    
    // Note we can select Median as pivot to guaranteed O(N) complexity always.
    int pivotIndex = left + rand() % (right-left+1);
    
    int partitionIndex = partition(arr, left, right, pivotIndex);

    if(partitionIndex >= k)
    {
        // Recur for right subarray
        return quickSelect(arr, left, partitionIndex-1, k);
    }
    
    if(partitionIndex < k-1)
    {
        // Recur for left subarray.
        return quickSelect(arr, partitionIndex+1, right, k);
    }

    return arr[partitionIndex];
}

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    vector<int> result(2);
    
    // Kth smallest element
    result[0] = quickSelect(arr, 0, n-1, k);
    
    // Kth largest element
    result[1] = quickSelect(arr, 0, n-1, n-k+1);

    return result;
}

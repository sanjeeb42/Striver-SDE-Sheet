#include<bits/stdc++.h>

int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int n=matrix.size(), m=matrix[0].size();
    int low=1e8, high=-1e8;
    for(int i=0;i<n;i++){
        low=min(low,matrix[i][0]);
        high=max(high,matrix[i][m-1]);
    }
        
    // Now we have a range to perform the binary search
    
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
        }
        
        if(cnt>(n*m)/2){
            high=mid-1;
        }
        else low=mid+1;
    }
    
    return low;
    
}

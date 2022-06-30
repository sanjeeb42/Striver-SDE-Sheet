#include<bits/stdc++.h>

vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    // Write your code here. 
    vector<int>ans;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    
    for(int i=0;i<k;i++){
        pq.push({arr[i][0],{i,0}});
    }
    
    while(pq.size()>0)
    {
        auto top=pq.top();
        pq.pop();
        int val=top.first;
        int array_index=top.second.first;
        int index_in_array=top.second.second;
        
        ans.push_back(val);
        
        if(arr[array_index].size()>index_in_array+1)
        {
            pq.push({arr[array_index][index_in_array+1], {array_index,index_in_array+1}});
        }
    }
    
    return ans;
}

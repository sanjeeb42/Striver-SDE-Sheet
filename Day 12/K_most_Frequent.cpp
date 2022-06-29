#include<bits/stdc++.h>

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    unordered_map<int,int>freq;
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    
    for(auto it: freq){
        pq.push({it.second,it.first});
        if(pq.size()>k){
            pq.pop();
        }
    }
    
    vector<int>ans;
    while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;

    
}

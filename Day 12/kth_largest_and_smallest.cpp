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

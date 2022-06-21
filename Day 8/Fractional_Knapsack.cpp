#include<bits/stdc++.h>
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs
    priority_queue<pair<double,int>>pq;
    for(int i=0;i<n;i++)
    {
        pq.push({items[i].second/(double)items[i].first,items[i].first});  
    }
    double res=0;
    while(w>0 && pq.empty()==false){
        auto it=pq.top();
        pq.pop();
        int weight=it.second;
        double val=it.first;
        int ans=min(weight,w);  
        w-=ans;
        res+=(ans*val);    
    }
    
    return res;
}

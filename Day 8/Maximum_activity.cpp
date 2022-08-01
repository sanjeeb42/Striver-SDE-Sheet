#include<bits/stdc++.h>
bool compare(pair<int,int>&a,pair<int,int>&b)
{
    //Sort in order of end time
    return b.second>a.second;
}
int maximumActivities(vector<int> &start, vector<int> &end) {
    // Write your code here.
    int n=start.size();
    vector<pair<int,int>>p;
    for(int i=0;i<n;i++){
        p.push_back(make_pair(start[i],end[i]));
    }  
    
    sort(p.begin(),p.end(),compare);
    
    int s_time=0;
    int cnt=0;
    
    for(int i=0;i<n;i++){
       if(p[i].first>=s_time) {
           cnt++;
           s_time=p[i].second;
       }
    }
    
    return cnt;  
}

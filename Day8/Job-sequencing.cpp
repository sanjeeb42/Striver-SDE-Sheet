#include<bits/stdc++.h>
bool compare(vector<int>&a,vector<int>&b){
    return a[1]>b[1];
}

int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    int max_avail_time=jobs[0][0];
    int n=jobs.size();
    for(int i=1;i<n;i++)
    {
        max_avail_time=max(max_avail_time,jobs[i][0]);
    }
    
     sort(jobs.begin(),jobs.end(),compare);
                           
//      for(auto it: jobs)
//                            {
//                                for(auto pq:it){
//                                    cout<<pq<<" ";
//                                }
//                                cout<<endl;
//                            }
    
    vector<int>gain(max_avail_time,0);
    for(int i=0;i<n;i++)
    {
        int time=(jobs[i][0])-1;
        int profit=(jobs[i][1]);
        if(gain[time]==0)
        {
            
            gain[time]=profit;
        }
        else while(time>=0)
        {
            if(gain[time]==0)
            {
                gain[time]=profit;
                break;
            }
            time--;
        }
    } 
        int sum=0;
        for(auto it:gain)
        {
          //cout<<it<<" ";
            sum+=it;
        }
    
       return sum  ;      
    
}

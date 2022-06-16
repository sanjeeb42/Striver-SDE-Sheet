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



// We can optimise it by using a set while inserting- For more explanation refer to codestudio


// Create a set named slots that store the elements in decreasing order. Insert all the elements from maxDeadline to 1 into the set.
// Run a loop from i = 0 to N and do:
// If the set is empty or jobs[i].deadline is less than the last element of the set, then we ignore this job as it can’t be completed and continue in the loop.
// Apply binary search on the set and find the nearest available slot that is less than or equal to jobs[i].deadline. Let’s name this as availableSlot.
// maxProfit = maxProfit + jobs[i].profit
// Increment numberOfJobs by 1.
// Remove the availableSlot from the set.
// Return the maxProfit and numberOfJobs.


/*
    Time Complexity : O(N *log max(N, maxDeadline))
    Space Complexity : O(maxDeadline)

    Where 'N' is size of the array "jobs" and 
    'maxDeadline' is the maximum among all the deadlines.
*/


// Custom Comparator function to sort the jobs in the decreasing order of their profit.
bool compare(vector<int> &job1, vector<int> &job2)
{
    return job1[1] > job2[1];
}

int jobScheduling(vector<vector<int>> &jobs)
{

    sort(jobs.begin(), jobs.end(), compare);

    int maxProfit = 0;
    int maxDeadline = 0;

    // Find the maximum deadline among all the jobs.
    for (int i = 0; i < jobs.size(); i++)
    {
        maxDeadline = max(maxDeadline, jobs[i][0]);
    }

    // Create a set "slots".
    set<int, greater<int>> slots;

    // Insert all the elements from maxDeadline to 1 into the set.
    for (int i = maxDeadline; i > 0; i--)
    {
        slots.insert(i);
    }

    for (int i = 0; i < jobs.size(); i++)
    {

        // If the set is empty or the deadline is less than the last element of the set, then ignore this job.
        if (slots.size() == 0 || jobs[i][0] < *slots.rbegin())
        {
            continue;
        }

        int availableSlot = *slots.lower_bound(jobs[i][0]);
        maxProfit = maxProfit + jobs[i][1];
        slots.erase(availableSlot);
    }

    return maxProfit;
}


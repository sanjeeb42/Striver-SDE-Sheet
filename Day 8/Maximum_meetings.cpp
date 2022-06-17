#include<bits/stdc++.h>
bool mycompare(vector<int>&a,vector<int>&b){
    
    if(b[2]>a[2]) return true;
    else if(b[2]==a[2]) return a[0]<b[0];
    
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    int n=start.size();
   vector<vector<int>> arr;
    for (int i = 0; i < n; i++)
    {
        vector<int> curr = {i + 1, start[i], end[i]};
        arr.push_back(curr);
    }
    sort(arr.begin(), arr.end(), mycompare);

//     for (auto it : arr)
//     {
//         for (auto pq : it)
//         {
//             cout << pq << " ";
//         }
//         cout << endl;
//     }
    vector<int> ans;
    int last_end = arr[0][2];
    ans.push_back(arr[0][0]);
    for (int i = 1; i < n; i++)
    {
        if (arr[i][1] > last_end)
        {
            ans.push_back(arr[i][0]);
            last_end = arr[i][2];
        }
    }
    return ans;
    
}

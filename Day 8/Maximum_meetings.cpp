//Look into copy- 
//My solution

#include<bits/stdc++.h>
bool mycompare(vector<int>&a,vector<int>&b){
    // Sorting in the increasing order of end time
    if(b[2]>a[2]) return true;
    //If end time equal , then task will lower index number is preffered
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



// Less Runtime -Just using a struct instead of vector Nothing more

/*
    Time Complexity: O(N * logN)
    Space Complexity: O(N)

    Where N is the number of meetings.
*/

#include <algorithm>

struct meet {
    int meetingID;
    int startTime;
    int endTime;
};

bool compare(struct meet a, struct meet b) {
    if (a.endTime == b.endTime) {
        return a.meetingID < b.meetingID;
    }
    else{
        return a.endTime < b.endTime;
    }
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();

    // Creating meeting array of size N.
    struct meet meeting[n];

    for (int i = 0; i < n; i++) {
        meeting[i].meetingID = i + 1;
        meeting[i].startTime = start[i];
        meeting[i].endTime = end[i];
    }

    // Sorting the meeting array in increasing order of end time using customized comparator.
    sort(meeting, meeting + n, compare);

    vector<int> result;

    // Taking the first meeting of sorted array as our first meeting.
    result.push_back(meeting[0].meetingID);
    int currentTime = meeting[0].endTime;

    for (int i = 1; i < n; i++) {

        // If startTime of current meeting is greater than our currentTime.
        // Then we will perform this meeting and update currentTime with endTime of the meeting.
        if (meeting[i].startTime > currentTime) {
            result.push_back(meeting[i].meetingID);
            currentTime = meeting[i].endTime;
        }
    }

    return result;
}


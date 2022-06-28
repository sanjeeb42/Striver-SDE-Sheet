#include<bits/stdc++.h>
void findMedian(int *arr, int n)
{
    // Write your code here
     priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;

    pq1.push(arr[0]);
    if(pq1.top()!=0){
    cout << pq1.top();}
    for (int i = 1; i < n; i++)
    {
        // We need to push to first pq1
        if (i % 2 == 0)
        {
            int tmp = pq2.top();
            if (tmp < arr[i])
            {
                pq2.pop();
                pq2.push(arr[i]);
                pq1.push(tmp);
            }
            else
            {
                pq1.push(arr[i]);
            }

            cout <<" "<< pq1.top();
        }
        else
        {
            int tmp = pq1.top();
            if (tmp > arr[i])
            {
                pq1.pop();
                pq1.push(arr[i]);
                pq2.push(tmp);
            }
            else
            {
                pq2.push(arr[i]);
            }

            cout <<" "<< (pq1.top() + pq2.top()) / 2;
        }
    }
}

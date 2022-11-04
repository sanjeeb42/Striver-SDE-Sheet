#include <bits/stdc++.h>
using namespace std;
#define ll long long

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> tmp(high - low + 1);

    int i = low, j = mid + 1, k =0;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            tmp[k++] = arr[i++];
        }
        else
            tmp[k++] = arr[j++];
    }
    while (i <= mid)
    {
        tmp[k++] = arr[i++];
    }
    while (j <= high)
    {
        tmp[k++] = arr[j++];
    }

    for (int i = 0; i < tmp.size(); i++)
    {
        arr[low + i] = tmp[i];
    }
}

void mergesort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    else
    {
        int mid = low + (high - low) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr)
    {
        cin >> it;
    }

    mergesort(arr, 0, n - 1);

    for(auto it: arr){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}

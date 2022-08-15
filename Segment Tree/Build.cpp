#include <bits/stdc++.h>
using namespace std;

void buildTree(vector<int> &arr, vector<int> &segTree, int index, int low, int high)
{
    if (low == high)
    {
        segTree[index] = arr[low];
        return;
    }
    int mid = low + (high - low) / 2;
    buildTree(arr, segTree, 2 * index + 1, low, mid);
    buildTree(arr, segTree, 2 * index + 2, mid + 1, high);
    segTree[index] = min(segTree[2 * index + 1], segTree[2 * index + 2]);
}

int query(int index, int segmentstart, int segmentend, vector<int> segTree, int querystart, int queryend)
{ // If no overlap
    if ((querystart > segmentend) or (queryend < segmentstart))
    {
        return INT_MAX;
    }
    // If complete overlap
    if (querystart <= segmentstart && queryend >= segmentend)
    {
        return segTree[index];
    }
    // If partial overlap
    int mid = segmentstart + (segmentend - segmentstart) / 2;
    int lf = query(2 * index + 1, segmentstart, mid, segTree, querystart, queryend);
    int rf = query(2 * index + 2, mid + 1, segmentend, segTree, querystart, queryend);
    return min(lf, rf);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
    vector<int> segTree(4 * n);
    buildTree(arr, segTree, 0, 0, n - 1);
    for (auto it : segTree)
    {
        cout << it << " ";
    }
    cout << endl;
    int querystart, queryend;
    cin >> querystart >> queryend;
    cout << query(0, 0, n - 1, segTree, querystart, queryend) << endl;
    int q;
    cin >> q;
    while (q--)
    {
        int querystart, queryend;
        cin >> querystart >> queryend;
        cout << query(0, 0, n - 1, segTree, querystart, queryend) << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        solve();
    }
    return 0;
}

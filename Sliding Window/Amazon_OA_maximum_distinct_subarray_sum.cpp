#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    vector<int> psum(n, 0);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        psum[i] = sum;
    }

    int ans = 0;
    unordered_map<int, int> mp;
    int j = 0, i = 0;
    while (j < n)
    {

        if (mp.find(arr[j]) == mp.end())
        {
            mp[arr[j]] = j;
            j++;
        }
        else
        {
            // Already Present
            // case 1- Out of Window
            // Do Nothing
            if (mp[arr[j]] < i)
            {
                mp[arr[j]] = j;
            }

            // CAse 2- Inside the Window
            else
            {
                i = mp[arr[j]]+1;
                mp[arr[j]] = j;
            }
            j++;
        }

        if (j - i == k)
        {
            // Do Some Calculations

            cout << i << " and " << j-1 << endl;
            int left = 0;
            if (i != 0)
            {
                left = psum[i - 1];
            }
            ans = max(ans, psum[j - 1] - left);
            i++;
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while (n--)
    {
        solve();
    }
    return 0;
}

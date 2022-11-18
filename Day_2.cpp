#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll max(ll &a, ll &b)
{
    return a > b ? a : b;
}

void solve()
{
    ll m, s;
    cin >> m >> s;
    vector<ll> arr(m);
    unordered_map<int, int> mp;
    ll maxi = -1;
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
        maxi = max(maxi, arr[i]);
    }

    ll i;
    for (i = 1; i <= 1000; i++)
    {
        
        if (mp.find(i) == mp.end())
        {
            mp[i]++;
            s -= i;
            if (s == 0)
                break;
            else if (s < 0)
            {
                cout << "NO" << endl;
                return;
            }
        }
        else if (mp[i] > 1)
        {
            cout << "NO" << endl;
            return;
        }
    }

    maxi = max(maxi, i);

    for (int j = 1; j <= maxi; j++)
    {
        if (mp[j] == 0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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

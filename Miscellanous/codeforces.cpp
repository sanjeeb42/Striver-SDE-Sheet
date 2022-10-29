#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll max(ll &a, ll &b)
{
    return a > b ? a : b;
}

ll min(ll &a, ll &b)
{
    return a > b ? b : a;
}


void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (auto &it : arr)
    {
        cin >> it;
    }
    ll maxi = LONG_MIN, mini = LONG_MAX;
    for (auto &it : arr)
    {
        maxi = max(maxi, it);
        mini = min(mini, it);
    }
    ll ans = abs(maxi - mini);

    ll currans = LONG_MAX;
    bool maxifnd = false, minifnd = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == maxi && maxifnd == false)
        {
            maxifnd = true;
            continue;
        }
        else if (arr[i] == mini && minifnd == false)
        {
            minifnd = true;
            continue;
        }

        ll val1 = abs(maxi - arr[i]);
        ll val2 = abs(maxi - arr[i]);
        currans = min(currans, max(val1, val2));
    }

    ans += currans;
    cout << ans << endl;
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

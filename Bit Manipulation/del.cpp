#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1e9 + 7

void solve()
{
    ll n, m, d;
    cin >> n >> m >> d;
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        ll tmp;
        cin >> tmp;
        mp[tmp] = i;
    }
    vector<ll> arr(m);
    for (auto &it : arr)
    {
        cin >> it;
    }

    ll ans = INT_MAX;
    for (int i = 1; i < m; i++)
    {
        ll num1 = arr[i - 1], num2 = arr[i];
        ll pos1 = mp[num1], pos2 = mp[num2];

        // cout<<pos1<<" and "<<pos2<<endl;

        if (pos1 > pos2 or pos2 > pos1 + d)
        {
            ans = 0;
            break;
        }
        else
        {
            ll diff1 = pos2 - pos1;
            ll diff2 = (pos1 + d) - pos2 + 1;

            //   cout<<"Diff1 is: "<<diff1<<" and diff2 is: "<<diff2<<endl;
            ll avail = pos1 - 1 + n - pos2;

            ll swaps1 = diff1, swaps2 = INT_MAX;
            if (avail >= diff2)
            {
                swaps2 = diff2;
            }
            ll mini = min(swaps1, swaps2);
            ans = min(ans, mini);
        }
    }

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

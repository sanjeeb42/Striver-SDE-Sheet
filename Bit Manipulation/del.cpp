#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1e9 + 7

void solve()
{
    ll n, coins;
    cin >> n >> coins;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < n; i++)
    {
        ll tmp;
        cin >> tmp;
        ll val = i + 1 + tmp;
        pq.push(val);
    }

    ll ans = 0;
    while (pq.size() > 0)
    {

        ll cost = pq.top();
        pq.pop();
        if (coins >= cost)
        {
            coins -= cost;
            ans++;
        }
        else
            break;
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

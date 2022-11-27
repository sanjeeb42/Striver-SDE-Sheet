#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    string s;
    cin >> s;
    int n = s.length();

    int cnt = 0;
    for (auto it : s)
    {
        if (it == 'N')
            cnt++;
    }

    if (cnt == 0)
    {
        cout << n << endl;
        return;
    }

    vector<int> penalties(n + 1, 0);
    penalties[n] = cnt;

    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == 'Y')
            penalties[i] = penalties[i + 1] + 1;
        else
            penalties[i] = penalties[i + 1] - 1;
    }

    for (auto it : penalties)
    {
        cout << it << endl;
    }
}

int solve1()
{
    string s;
    cin >> s;
    int n = s.length();

    vector<int> comesafter(n + 1, 0), notcomesbefore(n + 1, 0);
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == 'Y')
            cnt++;
        comesafter[i] = cnt;
    }

    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'N')
            cnt++;
        notcomesbefore[i + 1] = cnt;
    }

    // IF i am at a point and I know x people have come before and y people will come after
    // Then no of people not coming=n-(comebefore+comeafter)

    int ans = 0;
    int penalties = INT_MAX;

    for (int i = 0; i <= n; i++)
    {
       // cout << "i: " << i << " ";

        int comeafter = comesafter[i];
        int notcome = notcomesbefore[i];

        int currpenalties = notcome + comeafter;
        if (currpenalties < penalties)
        {
            penalties = currpenalties;
            ans = i;
        }

      //  cout << currpenalties << endl;
    }

    // cout << "Done " << ans << endl;
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
       cout<< solve1()<<endl;
    }

    return 0;
}

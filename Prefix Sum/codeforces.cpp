https://codeforces.com/contest/1749/problem/B

void solve()
{
   
    int n;
    cin >> n;
    vector<ll> a(n), b(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int maxindex = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (b[i] >= b[maxindex])
        {
            maxindex = i;
        }
    }

    ll ans = 0, addval = 0;
    for (int i = 0; i < maxindex; i++)
    {
        ans += a[i] + addval;
        addval = b[i];
    }

    ans += addval;
    addval = 0;
    for (int i = n - 1; i > maxindex; i--)
    {
        ans += a[i] + addval;
        addval = b[i];
    }
    ans += a[maxindex] + addval;

    cout<<ans<<endl;
}

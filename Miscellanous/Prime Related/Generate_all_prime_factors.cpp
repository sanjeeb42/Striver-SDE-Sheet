// Credits -- Geeksforgeeks Primefactor Functions
// Submitted by Sanjeeb

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1e9 + 7

void solve()
{
    ll n;
    cin >> n;
    unordered_map<int, int> mp;
    ll product = 1;
    // Grenerate all prime factors
    while (n % 2 == 0)
    {
        mp[2]++;
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            mp[i]++;
            n = n / i;
        }
    }
    if (n > 2)
        mp[n]++;
        
        
    // for(auto it: mp){
    //     cout<<it.first<<" -> "<<it.second<<endl;
    // }

    priority_queue<pair<ll, ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    for (auto it : mp)
    {
        product *= it.first;
        pq.push({it.second, it.first});
    }
    
    
    // while(pq.size()>0){
    //     cout<<pq.top().first<<" -> "<<pq.top().second<<endl;
    //     pq.pop();
    // }
    // cout<<"***********"<<endl;
    ll ans = 0;
    ll used = 0;
    while (pq.size() > 0)
    {
        auto front = pq.top();
        pq.pop();
        ll no = front.second, cnt = front.first-used;
        if(cnt<=0){
            product=product/no;
            continue;
        }
        used += cnt;
        ll curr = (product * cnt);
        ans += curr;
        product = product / no;
        
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


vector<int>primes;
    vector<int>visited;
    
    void prime(){
        visited.resize(1e4+1,0);
        for(int i=2;i*i<=1e4;i++){
            if(visited[i]==0){
                for(int j=i+1;j*i<=1e4;j++){
                    visited[i*j]=1;
                }
            }
        }
        
        for(int i=2;i<=1e4;i++){
            if(visited[i]==0){
                primes.push_back(i);
            }
        }
        
    }

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 0; i < n; i++) 
    cin >> a[i];
    vector<ll> c(n + 1);
    for (int i = 0; i < n; i++) 
    cin >> c[i];
    ll cost = accumulate(c.begin(), c.end(), 0LL);
    vector<ll> mp(n, 0);
    ll saved = 0;
    // basically we check in what way can we save the most in any non-decreasing subsequence (which is what the qn intends)
    for (int i = 0; i < n; i++) 
    {
        mp[i] = c[i];
        for (int j = 0; j < i; j++) 
        {
            if (a[j] <= a[i]) 
            {
                mp[i] = max(mp[i], mp[j] + c[i]);
            }
        }
        saved = max(saved, mp[i]);
    }
    cout << cost - saved << '\n';
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) 
    {
        solve();
    }
}
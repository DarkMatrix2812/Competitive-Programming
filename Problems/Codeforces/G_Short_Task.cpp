#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> ans(1e7 + 1, -1);
void solve()
{
    int c; 
    cin >> c;
    cout << ans[c] << endl;
}
int32_t main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> d(1e7 + 1, 0);
    // Precompute sum of divisors using sieve
    for (int i = 1; i <= 1e7; i ++) 
    {
        for (int j = i; j <= 1e7; j += i) 
        {
            d[j] += i;
        }
    }
    // Build answer array: minimum n such that d(n) = c
    for (int n = 1; n <= 1e7; n ++) 
    {
        if (d[n] <= 1e7 && ans[d[n]] == -1) 
        {
            ans[d[n]] = n;
        }
    }
    int t = 1;
    cin >> t;
    while (t--) 
    {
        solve();
    }
}   
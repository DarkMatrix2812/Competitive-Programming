#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> c(n);
    vector<int> v(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> c[i]; 
    }
    for (int i = 0; i < n; i ++)
    {
        cin >> v[i]; 
    }
    int C = 0; int V = 0;
    for (int i = 0; i < n; i ++)
    {
        C += c[i];
        V += (c[i] * v[i]);
    }
    vector<pair<int, int>> freq;
    for (int i = 0; i < n; i ++)
    {
        freq.push_back({v[i], c[i]});
    }
    sort(freq.rbegin(), freq.rend());
    int ans = 0; int value = 0;
    for (auto [v, c] : freq)
    {
        for (int i = 1; i <= c; i ++)
        {
            ans += 1;
            value += v;
            if (value * C >= (C - ans) * V)
            {
                cout << ans << endl;
                return;
            }
        }
    }
}
int32_t main() 
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
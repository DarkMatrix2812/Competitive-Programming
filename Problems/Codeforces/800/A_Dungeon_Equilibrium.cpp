#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> freq;
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
        freq[a[i]] += 1;
    }
    int ans = 0;
    for (auto p : freq)
    {
        if (p.second >= p.first) ans += (p.second - p.first);
        else ans += p.second;
    }
    cout << ans << endl;
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
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n); vector<int> b(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i ++)
    {
        cin >> b[i];
    }
    vector<int> pref(n + 1); //cumulative strikes
    pref[0] = 0;
    for (int i = 1; i < n + 1; i ++)
    {
        pref[i] = pref[i - 1] + b[i - 1];
    }
    sort(a.rbegin(), a.rend());
    int ans = 0;
    for (int level = 1; level <= n; level ++)
    {
        if (pref[level] > n) break;
        int x = a[pref[level] - 1]; // the pref[level] (strikes needed) -th sword
        ans = max(ans, level * x);
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
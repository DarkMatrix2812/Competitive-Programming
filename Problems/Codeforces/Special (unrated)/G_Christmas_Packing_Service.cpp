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
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i]; 
    }
    int ans = 0;
    vector<int> prefix_max(n);
    prefix_max[0] = a[0];
    for (int i = 1; i < n; i ++)
    {
        prefix_max[i] = max(a[i], prefix_max[i - 1]);
    }
    vector<int> suffix_min(n);
    suffix_min[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i --)
    {
        suffix_min[i] = min(a[i], suffix_min[i + 1]);
    }
    for (int i = 0; i < n - 1; i ++)
    {
        if (prefix_max[i] <= suffix_min[i + 1]) ans += 1;
    }
    cout << ans + 1 << endl;
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
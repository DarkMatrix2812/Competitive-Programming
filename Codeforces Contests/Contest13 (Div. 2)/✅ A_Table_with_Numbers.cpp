#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, h, l;
    cin >> n >> h >> l;
    vector<int> a(n);
    int x = 0; int y = 0; int both = 0;
    int ans = 0;
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
        if (a[i] <= h && a[i] <= l) both += 1;
        else if (a[i] <= h) x += 1;
        else if (a[i] <= l) y += 1;
    }
    ans += min(x, y);
    x -= min(x, y);
    y -= min(x, y);
    ans += min(x, both);
    both -= min(x, both);
    ans += min(y, both);
    both -= min(y, both);
    cout << ans + (both / 2) << endl;
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
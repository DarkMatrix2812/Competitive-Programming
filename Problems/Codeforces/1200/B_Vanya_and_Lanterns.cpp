#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n; int l;
    cin >> n >> l;
    vector<int> a(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int gap = 0;
    for (int i = 1; i < n; i ++)
    {
        gap = max(a[i] - a[i - 1], gap);
    }
    long double ans = max({(long double)gap / 2.0L, (long double)a[0], (long double)(l - a[n - 1])});
    cout << fixed << setprecision(10) << ans;
}   
int32_t main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) 
    {
        solve();
    }
}
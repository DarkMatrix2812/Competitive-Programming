#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    vector<int> pref(n + 1);
    pref[0] = 0;
    for (int i = 1; i < n + 1; i ++)
    {
        pref[i] = pref[i - 1] + a[i - 1];
    }
    double ans = 0;
    for (int i = 1; i <= n - k + 1; i ++)
    {
        ans += (pref[i + k - 1] - pref[i - 1]);
    }
    cout << fixed << setprecision(6) << ans / (n - k + 1) << endl;
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
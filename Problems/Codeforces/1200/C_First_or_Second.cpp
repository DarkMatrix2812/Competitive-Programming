#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1); vector<int> pref1(n - 1); vector<int> pref(n + 1);
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    for (int i = 1; i <= n - 2; i ++)
    {
        pref1[i] = pref1[i - 1] + abs(a[i + 1]);
    }
    int ans = -1 * (pref[n] - pref[1]);
    for (int i = 1; i <= n - 1; i ++)
    {
        ans = max(ans, a[1] + pref1[i - 1] - (pref[n] - pref[i + 1]));
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
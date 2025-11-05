#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    vector<int> pref(n + 1);
    for (int i = 1; i < n + 1; i ++)
    {
        pref[i] = pref[i - 1] + a[i - 1];
    }
    map<int, int> seen;
    int ans = 0;
    for (int i = 0; i < pref.size(); i ++)
    {
        int req = pref[i] - x;
        ans += seen[req];
        seen[pref[i]] += 1;
    }
    cout << ans << endl;
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
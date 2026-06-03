#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n; int m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int sum = 0;
    int l = 0; int r = 0; int ans = 0;
    for (int r = 0; r < n; r++)
    {
        sum += a[r];
        while (l <= r && (a[r] - a[l] > 1))
        {
            sum -= a[l];
            l += 1;
        }
        while (l <= r && sum > m)
        {
            sum -= a[l];
            l += 1;
        }
        ans = max(ans, sum);
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
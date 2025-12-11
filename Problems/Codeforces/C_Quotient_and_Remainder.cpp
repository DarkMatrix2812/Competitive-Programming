#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> q(n), r(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> q[i];
    }
    for (int i = 0; i < n; i ++)
    {
        cin >> r[i];
    }
    sort(q.begin(), q.end());
    sort(r.begin(), r.end());
    reverse(r.begin(), r.end());
    // checking smallest quotient and largest remainder
    int ans = 0; int curr = 0;
    for (int i = 0; i < n && curr < n; i ++)
    {
        if ((r[i] + 1) * q[curr] + r[i] <= k) // key part, notice that the smallest value of y must work, otherwise no (x, y) exists
        {
            ans += 1;
            curr += 1;
        }
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
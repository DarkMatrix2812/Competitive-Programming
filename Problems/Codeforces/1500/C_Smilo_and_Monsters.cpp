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
    sort(a.begin(), a.end());
    int l = 0; int r = n - 1;
    int x = 0; // combo counter
    int ans = 0;
    while (l < r)
    {
        if (x + a[l] < a[r])
        {
            ans += a[l];
            x += a[l];
            a[l] = 0;
        }
        else
        {
            int need = a[r] - x;
            a[l] -= need;
            ans += need;
            ans += 1; // combo attack
            a[r] = 0;
            x = 0;
        }
        if (a[l] == 0) l += 1;
        if (a[r] == 0) r -= 1;
    }
    if (l == r)
    {
        ans += min((a[r] - x + 1) / 2 + 1, a[r]);
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
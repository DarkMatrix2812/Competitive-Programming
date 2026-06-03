#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int L = min(k - 1, n - k); int R = max(k - 1, n - k);
    int l = 0; int r = 0;
    while (true)
    {
        if (l < L && l + 1 + r + max(l + 1, r) - 1 <= m) l += 1;
        if (r < R && r + 1 + l + max(l, r + 1) - 1 <= m) r += 1;
        else break;
    }
    cout << l + r + 1 << endl;
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
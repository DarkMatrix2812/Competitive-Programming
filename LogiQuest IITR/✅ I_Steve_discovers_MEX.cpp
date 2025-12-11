#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, b, c;
    cin >> n >> b >> c;
    if (c >= n)
    {
        cout << n << endl;
        return;
    }
    if (b == 0 && (c == n - 1 || c == n - 2))
    {
        cout << n - 1 << endl;
        return;
    }
    if (b == 0 && c <= n - 3) // this case leads to infinite loop of continous altering of leftmost max element - hence, -1
    {
        cout << -1 << endl;
        return;
    }
    // otherwise ans is just n - k, where k is no. of. numbers already present in [0, n - 1]
    // now, we could just do this in O(n) but the constraints prevent us
    // we need O(logn) or better - this sceams binary search!
    // but we can't apply binary search on a vector of 1e18 length when we can't even store it
    int k = min(n, (n - c - 1) / b + 1);
    cout << max(0LL, n - k) << endl;
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
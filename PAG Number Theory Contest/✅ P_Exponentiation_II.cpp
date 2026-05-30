#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int e = 1;
    int mod = 1000000007;
    while (c > 0)
    {
        if (c % 2 == 1) e = e * b % (mod - 1);
        b = b * b % (mod - 1);
        c /= 2;
    }
    int ans = 1;
    while (e > 0)
    {
        if (e % 2 == 1) ans = ans * a % mod;
        a = a * a % mod;
        e /= 2;
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
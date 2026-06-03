#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    // possibilities only when gcd(a, b) = b
    for (int b = 1; b <= m; b ++) 
    {
        for (int a = b; a <= n; a += b)
        {
            if ((a / b + 1) % b == 0)
            {
                ans += 1;
            }
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
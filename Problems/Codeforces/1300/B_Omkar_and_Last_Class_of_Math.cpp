#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    if (n % 2 == 0) cout << n / 2 << " " << n / 2 << endl;
    else
    {
        int ans = 1;
        for (int i = 1; i * i <= n; i ++)
        {
            if (n % i == 0)
            {
                if (i <= n / 2) ans = max(ans, i);
                if (n / i <= n / 2) ans = max(ans, n / i);
            }
        }
        cout << ans << " " << n - ans << endl;
    }
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
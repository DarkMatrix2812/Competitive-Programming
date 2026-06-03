#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    if (n % 2 != 0)
    {
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    for (int i = 0; i <= n / 2; i ++)
    {
        if ((n - 2 * i) % 4 == 0)
        {
            ans += 1;
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
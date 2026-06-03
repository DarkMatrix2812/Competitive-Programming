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
    for (int i = 0; i <= n; i ++)
    {
        for (int j = 0; j <= m; j ++)
        {
            if (i * i + j == n && j * j + i == m)
            {
                ans += 1;
            }
        }
    }
    cout << ans;
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
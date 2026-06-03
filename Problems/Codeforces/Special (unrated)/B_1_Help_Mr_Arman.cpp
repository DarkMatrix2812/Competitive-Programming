#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    if (a > b) ans += 1;
    if (b > c) ans += 1;
    if (a > c) ans += 1;
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
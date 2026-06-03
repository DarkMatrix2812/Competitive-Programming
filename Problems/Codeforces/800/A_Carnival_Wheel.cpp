#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int l, a, b;
    cin >> l >> a >> b;
    int ans = (a + b) % l;
    int curr = (a + b) % l;
    while (curr != a)
    {
        curr = (curr + b) % l;
        ans = max(ans, curr);
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
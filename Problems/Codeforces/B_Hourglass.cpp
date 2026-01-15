#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int s, k, m;
    cin >> s >> k >> m;
    if ((m / k) % 2 == 1) 
    {
        m = m - (m / k) * k;
        cout << max(0LL, min(s, k) - m) << endl;
    }
    else 
    {
        m = m - (m / k) * k;
        cout << max(0LL, s - m) << endl;
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
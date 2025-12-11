#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    if (n >= 1000000007)
    {
        cout << 0 << endl;
        return;
    }
    int p = 1;
    for (int i = 1; i <= n; i ++)
    {
        p = p * i % 1000000007;
    }
    cout << p << endl;
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
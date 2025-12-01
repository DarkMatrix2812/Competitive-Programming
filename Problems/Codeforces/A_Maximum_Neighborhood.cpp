#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    if (n == 1) cout << 1 << endl;
    else if (n == 2) cout << 9 << endl;
    else cout << max(n * n + n * n - 1 + n * n - 2 + n * n - n - 1, n * n - 1 - n + n * n - n + n * n - n - 2 + n * n - 1 + n * n - 2 * n - 1) << endl;
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
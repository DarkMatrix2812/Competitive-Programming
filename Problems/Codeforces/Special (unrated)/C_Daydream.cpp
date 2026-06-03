#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    int res = 0;
    for (int i = 0; i < n; i ++)
    {
        res += (4 & a[i]);
    }
    if (res == 0) cout << 4 << " " << res << " " << 0 << endl;
    else cout << 4 << " " << res << " " << 2 << endl;;
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
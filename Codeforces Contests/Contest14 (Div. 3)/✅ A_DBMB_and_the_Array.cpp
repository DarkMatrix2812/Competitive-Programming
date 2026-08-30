#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, s, x;
    cin >> n >> s >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    if (s < accumulate(a.begin(), a.end(), 0LL))
    {
        cout << "NO" << endl;
        return;
    }
    if ((s - accumulate(a.begin(), a.end(), 0LL)) % x == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
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
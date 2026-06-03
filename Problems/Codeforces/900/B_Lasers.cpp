#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <numeric>
using ll = long long;
using namespace std;
void solve()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> a(n);
    vector<int> b(m);
    ll ans = 0;
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
        if (a[i] <= y)
        ans += 1;
    }
    for (int i = 0; i < m; i ++)
    {
        cin >> b[i];
        if (b[i] <= x)
        ans += 1;
    }
    cout << ans << endl;

}
int main() 
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
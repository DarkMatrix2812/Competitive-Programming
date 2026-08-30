#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> rollback;
    int d = 0;
    for (int i = 0; i < n; i ++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        d += (b - 1) * a;
        rollback.push_back(b * a - c);
    }
    if (d >= x) //reach without rollback
    {
        cout << 0 << endl;
        return;
    }
    sort(rollback.rbegin(), rollback.rend());
    if (rollback[0] <= 0) //rollback doesnt help
    {
        cout << -1 << endl;
        return;
    }
    int ans = 0;
    int need = x - d;
    cout << (need + rollback[0] - 1) / rollback[0] << endl;
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
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n); vector<int> b(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i ++)
    {
        cin >> b[i];
    }
    vector<int> mx(n + 2);
    mx[n + 1] = 0;
    for (int i = n; i >= 1; i--)
    {
        mx[i] = max(mx[i + 1], max(a[i - 1], b[i - 1]));
    }
    vector<int> pref(n + 1);
    pref[0] = 0;
    for (int i = 1; i < n + 1; i ++)
    {
        pref[i] = pref[i - 1] + mx[i];
    }
    for (int i = 0; i < q; i ++)
    {
        int l, r;
        cin >> l >> r;
        cout << pref[r] - pref[l - 1] << " ";
    }
    cout << endl;
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
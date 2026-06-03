#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, char> actual, sorted;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        if (i % 2 == 0) actual[a[i]] = 'o';
        else actual[a[i]] = 'e';
    }
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i ++)
    {
        if (i % 2 == 0) sorted[a[i]] = 'o';
        else sorted[a[i]] = 'e';
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (actual[a[i]] != sorted[a[i]]) ans += 1;
    }
    cout << ans / 2 << endl;
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
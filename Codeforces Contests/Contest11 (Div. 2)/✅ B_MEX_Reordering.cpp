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
    int c0 = 0; int c1 = 0;
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
        if (a[i] == 0) c0 += 1;
        else if (a[i] == 1) c1 += 1;
    }
    if (c0 == 0)
    {
        cout << "NO" << endl;
        return;
    }
    if (c1 == 0 && c0 >= 2)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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
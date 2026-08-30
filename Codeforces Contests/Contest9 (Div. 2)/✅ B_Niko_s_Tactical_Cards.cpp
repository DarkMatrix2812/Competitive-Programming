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
    vector<int> b(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i ++)
    {
        cin >> b[i];
    }
    int p1 = 0, p2 = 0; 
    for (int i = 0; i < n; i ++) 
    {
        int tmp1 = max(p1 - a[i], b[i] - p2);
        int tmp2 = min(p2 - a[i], b[i] - p1);
        p1 = tmp1;
        p2 = tmp2;
    }
    cout << p1 << "\n";
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
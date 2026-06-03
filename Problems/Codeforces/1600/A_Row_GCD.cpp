#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);
    return b == 0 ? a : gcd(b, a % b);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i ++)
    {
        cin >> b[i];
    }
    if (n == 1) 
    {
        for (int i = 0; i < m; i ++)
        {
            cout << a[0] + b[i] << " ";
        }
        return;
    }
    int g = a[1] - a[0];
    for (int i = 1; i < n; i ++)
    {
        g = gcd(g, a[i] - a[i - 1]);
    }
    for (int i = 0; i < m; i ++)
    {
        cout << gcd(a[0] + b[i], g) << " ";
    }
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
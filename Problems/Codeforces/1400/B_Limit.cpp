#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
int gcd(int a, int b) 
{
    if (b == 0) 
    {
        return a;
    }
    return gcd(b, a % b);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    for (int i = 0; i < n + 1; i ++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n + 1; i ++)
    {
        cin >> b[i];
    }
    if (n > m && a[0] * b[0] > 0) cout << "Infinity";
    else if (n > m && a[0] * b[0] < 0) cout << "-Infinity";
    else if (n == m)
    {
        if (a[0] * b[0] > 0) cout << a[0]/gcd(a[0], b[0]) << "/" << b[0]/gcd(a[0], b[0]);
        else cout << "-" << abs(a[0]/gcd(a[0], b[0])) << "/" << abs(b[0]/gcd(a[0], b[0]));
    }
    else cout << "0/1";
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
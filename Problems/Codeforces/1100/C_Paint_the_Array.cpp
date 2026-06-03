#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
int gcd(int a, int b) 
{
    return b == 0 ? a : gcd(b, a % b);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i]; 
    }
    int flag = 0;
    int g1 = a[0];
    for (int i = 2; i < n; i += 2)
    {
        g1 = gcd(g1, a[i]);
    }
    for (int i = 1; i < n; i += 2)
    {
        if (a[i] % g1 == 0) 
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << g1 << endl;
        return;
    }
    flag = 0;
    int g2 = a[1];
    for (int i = 3; i < n; i += 2)
    {
        g2 = gcd(g2, a[i]);
    }
    for (int i = 0; i < n; i += 2)
    {
        if (a[i] % g2 == 0) 
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0) 
    {
        cout << g2 << endl;
        return;
    }
    cout << 0 << endl;
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
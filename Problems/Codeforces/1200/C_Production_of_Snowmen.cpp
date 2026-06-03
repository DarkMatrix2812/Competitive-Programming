#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i ++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i ++)
    {
        cin >> c[i];
    }
    vector<bool> valid1(n, true);
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            if (a[i] >= b[j]) valid1[(j - i + n) % n] = false;
        }
    }
    int c1 = 0;
    for (bool b : valid1)
    {
        if (b == true) c1 += 1;
    }
    vector<bool> valid2(n, true);
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            if (b[i] >= c[j]) valid2[(j - i + n) % n] = false;
        }
    }
    int c2 = 0;
    for (bool b : valid2)
    {
        if (b == true) c2 += 1;
    }
    cout << n * c1 * c2 << endl;
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
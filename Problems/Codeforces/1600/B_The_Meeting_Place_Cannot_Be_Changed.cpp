#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> x[i];
    }
    vector<int> v(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> v[i];
    }
    // we do binary search on t (the time taken);
    long double t = 0;
    long double start = 0; long double stop = 1e9;
    for (int it = 0; it < 100; it ++)
    {
        long double mid = start + (stop - start) / 2.0;
        long double l = -1e18;
        long double r = 1e18;
        for (int i = 0; i < n; i ++)
        {
            l = max(l, x[i] - v[i] * mid);
            r = min(r, x[i] + v[i] * mid);
        }
        if (l <= r) // if boundary conditions valid
        {
            t = mid;
            stop = mid;
        }
        else
        {
            start = mid;
        }
    }
    cout << fixed << setprecision(12) << t;
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
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int r = a % b;
    for (int i = 1; i <= 100000; i ++)
    {
        int q = (r * 10) / b;
        r = (r * 10) % b;
        if (q == c)
        {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
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
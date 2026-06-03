#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int a, b;
    cin >> a >> b;
    int tmp1 = a; int tmp2 = b;
    // top layer white
    int layerw = 1;
    while (true)
    {
        if (layerw % 2 == 1)
        {
            if (tmp1 < pow(2, layerw - 1)) break;
            tmp1 -= pow(2, layerw - 1);
        }
        else
        {
            if (tmp2 < pow(2, layerw - 1)) break;
            tmp2 -= pow(2, layerw - 1);
        }
        layerw += 1;
    }

    // top layer dark
    int layerd = 1;
    while (true)
    {
        if (layerd % 2 == 1)
        {
            if (b < pow(2, layerd - 1)) break;
            b -= pow(2, layerd - 1);
        }
        else
        {
            if (a < pow(2, layerd - 1)) break;
            a -= pow(2, layerd - 1);
        }
        layerd += 1;
    }
    cout << max(layerw, layerd) - 1 << endl;
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
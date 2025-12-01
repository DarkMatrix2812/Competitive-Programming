#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int a, b, n;
    cin >> a >> b >> n;
    if (b <= a / n || a <= b)
    {
        cout << 1 << endl;
        return;
    }
    cout << 2 << endl;
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
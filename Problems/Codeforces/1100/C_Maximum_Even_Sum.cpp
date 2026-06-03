#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int a, b;
    cin >> a >> b;
    if (a * b % 2 == 1) 
    {
        cout << a * b + 1 << endl;
        return;
    }
    if (a % 2 == 0 && b % 2 == 1)
    {
        cout << -1 << endl;
        return;
    }
    if (a % 2 == 0 && b % 2 == 0)
    {
        cout << a * (b / 2) + 2 << endl;
        return;
    }
    if (a % 2 == 1 && b % 4 == 0)
    {
        cout << a * (b / 2) + 2 << endl;
        return;
    }
    cout << -1 << endl;
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
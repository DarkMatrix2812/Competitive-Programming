#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve()
{
    int a; int b;
    cin >> a >> b;
    if (a == b)
    {
        cout << 0 << endl;
        return;
    }
    if ((a ^ b) > a && a < b)
    {
        cout << -1 << endl;
        return;
    }
    if ((a ^ b) > a && a > b)
    {
        cout << 2 << endl;
        cout << b << " " << a << endl;
        return;
    }
    if ((a ^ b) < a)
    {
        cout << 1 << endl;
        cout << (a ^ b) << endl;
        return;
    }
}
int main() 
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
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == b && b == c && c == d)
    cout << "YES" << endl;
    else cout << "NO" << endl;
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
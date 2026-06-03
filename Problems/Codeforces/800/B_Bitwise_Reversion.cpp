#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve()
{
    int x; int y; int z;
    cin >> x >> y >> z;
    if (((x & y) == (y & z)) && ((y & z) == (x & z)))
    {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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
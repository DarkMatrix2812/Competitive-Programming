#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    //the move '8' is corresponding to two '4's (we can just consider it as up then right or vice-versa)
    x = llabs(x);
    y = llabs(y);
    int c1 = 0; int c2 = 0;
    for (char c : s)
    {
        if (c == '4') c1 += 1;
        else c2 += 1;
    }
    if ((c1 + 2 * c2) >= (x + y) && (c1 + c2) >= max(x, y)) cout << "YES" << endl;
    else cout << "NO" << endl;
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
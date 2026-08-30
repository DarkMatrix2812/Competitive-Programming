#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int r, x, d, n;
    cin >> r >> x >> d >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (char c : s)
    {
        if (c == '1')
        {
            ans += 1;
            r -= d;
        }
        else
        {
            if (r < x) 
            {
                ans += 1;
                r -= d;
            }
        }
    }
    cout << ans << endl;
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
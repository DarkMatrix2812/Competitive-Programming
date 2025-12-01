#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = s.length() - 2; i >= 0; i --)
    {
        if (s[i] != s[i + 1]) 
        {
            ans += 1;
            s[i] = s[i + 1];
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
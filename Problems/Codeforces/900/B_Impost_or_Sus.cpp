#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int ans = 0;
    if (s[0] == 'u')
    {
        s[0] = 's';
        ans += 1;
    }
    for (int i = 1; i < s.length() - 1; i ++)
    {
        if (s[i] == 'u' && s[i + 1] == 'u')
        {
            s[i + 1] = 's';
            ans += 1;
        }
    }
    if (s.back() == 'u')
    {
        s.back() = 's';
        ans += 1;
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
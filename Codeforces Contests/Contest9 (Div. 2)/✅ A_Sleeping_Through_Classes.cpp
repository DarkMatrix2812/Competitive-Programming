#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int awake = 0, ans = 0;
    for (int i = 0; i < n; i ++) 
    {
        if (awake > 0) 
        {
            awake -= 1;
        } 
        else if (s[i] == '0') 
        {
            ans += 1;
        }
        if (s[i] == '1') 
        {
            awake = k;
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
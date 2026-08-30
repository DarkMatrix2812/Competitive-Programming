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
    s = s + s;
    int mx = 0; int curr = 0;
    for (char c : s)
    {
        if (c == '0')
        {
            curr += 1;
            mx = max(mx, curr);
        }
        else
        {
            curr = 0;
        }
    }
    cout << mx << endl;
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
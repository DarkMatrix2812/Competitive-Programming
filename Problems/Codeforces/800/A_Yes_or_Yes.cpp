#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int cnt = 0;
    for (char c : s)
    {
        if (c == 'Y') cnt += 1;
    }
    if (cnt >= 2) cout << "NO" << endl;
    else cout << "YES" << endl;
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
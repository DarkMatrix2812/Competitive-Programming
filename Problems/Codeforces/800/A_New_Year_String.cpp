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
    if (s.find("2026") != string::npos || s.find("2025") == string::npos)
    {
        cout << 0 << endl;
        return;
    }
    if (s.find("2025") != string::npos)
    {
        cout << 1 << endl;
        return;
    }
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
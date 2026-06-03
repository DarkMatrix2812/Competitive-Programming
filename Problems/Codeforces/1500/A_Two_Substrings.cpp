#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int pos1 = s.find("AB");
    if (pos1 != string::npos && s.find("BA", pos1 + 2) != string::npos)
    {
        cout << "YES" << endl;
        return;
    }
    int pos2 = s.find("BA");
    if (pos2 != string::npos && s.find("AB", pos2 + 2) != string::npos)
    {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}
int32_t main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) 
    {
        solve();
    }
}
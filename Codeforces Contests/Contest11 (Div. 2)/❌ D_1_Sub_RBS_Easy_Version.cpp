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
    int last = -1;
    for (int i = 0; i < n; i ++)
    {
        if (s[i] == '(') last = i;
    }
    bool ok = false;
    for (int i = 0; i < last - 1; i ++)
    {
        if (s[i] == ')' && s[i + 1] == '(')
        {
            ok = true;
            break;
        }
    }
    if (ok) cout << n - 2 << endl;
    else cout << -1 << endl;
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
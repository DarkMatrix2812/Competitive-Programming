#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int start = -1; int stop = -1; int count = 0;
    for (int i = 0; i < s.length(); i ++)
    {
        if (s[i] == '>')
        {
            start = i;
            break;
        }
    }
    for (int i = s.length() - 1; i >= 0; i --)
    {
        if (s[i] == '<')
        {
            stop = i;
            break;
        }
    }
    for (int i = 0; i < s.length(); i ++)
    {
        if (s[i] == '*')
        {
            count += 1;
        }
    }
    if (s.find("**") != string::npos || s.find(">*") != string::npos || s.find("*<") != string::npos || s.find("><") != string::npos)
    {
        cout << -1 << endl;
        return;
    }
    if (s.length() == 1)
    {
        cout << 1 << endl;
        return;
    }
    if (start != -1 && stop != -1) cout << max((long long)stop + 1 + count, (long long)s.length() - start + count) << endl;
    if (start == -1 || stop == -1) cout << s.length() << endl;
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
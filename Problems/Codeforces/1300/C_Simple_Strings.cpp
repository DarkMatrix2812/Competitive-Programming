#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    string s;
    cin >> s;
    if (s.length() == 2)
    {
        if (s[0] != s[1]) cout << s;
        else
        {
            char c = 'a';
            while (c == s[1]) c += 1;
            s[0] = c;
            cout << s;
        }
        return;
    }
    for (int i = 1; i < s.length() - 1; i ++)
    {
        if (s[i] == s[i - 1] && s[i] == s[i + 1])
        {
            char c = 'a';
            while (c == s[i - 1]) c += 1;
            s[i] = c;
        }
    }
    for (int i = 1; i < s.length() - 1; i ++)
    {
        if (s[i] == s[i - 1] || s[i] == s[i + 1])
        {
            char c = 'a';
            while (c == s[i - 1] || c == s[i + 1]) c += 1;
            s[i] = c;
        }
    }
    cout << s;
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
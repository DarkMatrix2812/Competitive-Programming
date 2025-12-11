#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    string s, t;
    cin >> s;
    cin >> t;
    map<char, int> mp;
    for (char c : t)
    {
        mp[c] += 1;
    }
    for (char c : s)
    {
        mp[c] -= 1;
    }
    for (auto p : mp)
    {
        if (p.second < 0)
        {
            cout << "Impossible" << endl;
            return;
        }
    }
    string rem = "";
    for (int i = 0; i < 26; i ++)
    {
        for (int j = 0; j < mp[char('a' + i)]; j ++)
        {
            rem.push_back(char('a' + i));
        }
    }
    string ans = "";
    int i = 0; int j = 0;
    // merging process of rem and s
    while (i < rem.size() || j < s.size())
    {
        // just greedy checking of smaller char to insert
        if (i == rem.size()) 
        {
            ans.push_back(s[j]);
            j += 1;
        }
        else if (j == s.size())
        {
            ans.push_back(rem[i]);
            i += 1;
        }
        else if (rem[i] < s[j])
        {
            ans.push_back(rem[i]);
            i += 1;
        }
        else if (rem[i] > s[j]) 
        {
            ans.push_back(s[j]);
            j += 1;
        }
        // this is a special case, if the chars are same, THEN we need to scan forward to choose whether to take from rem or s
        else
        {
            int k = j;
            while (k < s.size() && s[k] == rem[i])
            {
                k += 1;
            }
            if (k == s.size() || s[k] > rem[i]) 
            {
                ans.push_back(rem[i]);
                i += 1;
            }
            else
            {
                ans.push_back(s[j]);
                j += 1;
            }
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
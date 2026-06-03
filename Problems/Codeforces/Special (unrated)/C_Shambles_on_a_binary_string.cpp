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
    string t;
    cin >> t;
    if (s == t)
    {
        cout << 0 << endl;
        return;
    }
    int c1 = 0; int c2 = 0;
    for (int i = 0; i < n; i ++)
    {
        if (s[i] == '1') c1 += 1;
    }
    for (int i = 0; i < n; i ++)
    {
        if (t[i] == '1') c2 += 1;
    }
    if (c1 != c2) 
    {
        cout << -1 << endl;
        return;
    }
    vector<pair<int,int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == t[i]) continue;
        if (s[i] == '0' && t[i] == '1')
        {
            int j = -1;
            for (int k = i + 1; k < n; k++)
            {
                if (s[k] == '1' && t[k] == '0')
                {
                    j = k;
                    break;
                }
            }
            if (j == -1)
            {
                cout << -1 << '\n';
                return;
            }
            reverse(s.begin() + i, s.begin() + j + 1);
            ans.push_back({i + 1, j + 1});
        }
        else
        {
            int j = -1;
            for (int k = n - 1; k >= i; k--)
            {
                if (s[k] == '0' && t[k] == '1')
                {
                    j = k;
                    break;
                }
            }
            if (j == -1)
            {
                cout << -1 << '\n';
                return;
            }
            reverse(s.begin() + i, s.begin() + j + 1);
            ans.push_back({i + 1, j + 1});
        }
    }
    cout << ans.size() << '\n';
    for (auto &p : ans)
    {
        cout << p.first << " " << p.second << endl;
    }
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
 
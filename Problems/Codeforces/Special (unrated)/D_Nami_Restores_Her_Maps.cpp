#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    string s;
    cin >> s;
    vector<map<int, int>> states;
    map<int, int> mp;
    states.push_back(mp);
    for (int i = 0; i < n; i ++)
    {
        if (s[i] == 'L')
        {
            mp[a[i]] += 1;
        }
        else
        {
            mp[a[i]] -= 1;
        }
        if (mp[a[i]] == 0) mp.erase(a[i]);
        states.push_back(mp);
    }
    map<map<int, int>, int> freq;
    for (auto x : states)
    {
        freq[x] += 1;
    }
    int ans = 0;
    for (auto x : freq)
    {
        ans += (x.second * (x.second - 1) / 2);
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
 
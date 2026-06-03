#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n; int m;
    cin >> n >> m;
    vector<int> a(n);
    vector<pair<int,int>> pairs(m);
    multiset<int> swords;
    vector<bool> dead(m, false);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
        swords.insert(a[i]);
    }
    for (int i = 0; i < m; i ++)
    {
        cin >> pairs[i].first;
    }
    for (int i = 0; i < m; i ++)
    {
        cin >> pairs[i].second;
    }
    sort(pairs.begin(), pairs.end());
    for (int i = 0 ; i < m; i ++)
    {
        auto idx = swords.lower_bound(pairs[i].first);
        if (idx != swords.end() && pairs[i].second > 0)
        {
            swords.erase(idx);
            swords.insert(max(*idx, pairs[i].second));
            dead[i] = true;
        }
    }
    for (int i = 0 ; i < m; i ++)
    {
        if (dead[i]) continue;
        auto idx = swords.lower_bound(pairs[i].first);
        if (idx != swords.end() && pairs[i].second == 0)
        {
            swords.erase(idx);
            dead[i] = true;
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i ++)
    {
        if (dead[i]) ans += 1;
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
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    vector<int> t(n);
    multiset<int> tickets;
    for (int i = 0; i < n; i ++)
    {
        cin >> h[i];
        tickets.insert(h[i]);
    }
    sort(h.begin(), h.end());
    for (int i = 0; i < m; i ++)
    {
        cin >> t[i];
        auto x = tickets.upper_bound(t[i]);
        if (x == tickets.begin())
        {
            cout << -1 << endl;
        }
        else
        {
            -- x;
            cout << *x << endl;
            tickets.erase(x);
        }
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
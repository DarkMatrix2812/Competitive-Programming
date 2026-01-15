#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    queue<pair<int, int>> q;
    unordered_set<int> seen;
    q.push({n, 0});
    seen.insert(n);
    while (!q.empty())
    {
        auto [x, time] = q.front();
        q.pop();
        if (x == k)
        {
            cout << time << endl;
            return;
        }
        if (x < k) continue;
        if (x / 2 >= k && !seen.count(x / 2))
        {
            seen.insert(x / 2);
            q.push({x / 2, time + 1});
        } 
        if (x - x / 2 >= k && !seen.count(x - x / 2))
        {
            seen.insert(x - x / 2);
            q.push({x - x / 2, time + 1});
        }
    }
    cout << -1 << endl;
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
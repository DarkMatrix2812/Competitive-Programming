#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    set<int> a;
    vector<int> dp(n + 1, INT_MAX); // minimum no. of elements needed to reach no. x
    for (int i = 0; i < n; i ++)
    {
        int x;
        cin >> x;
        a.insert(x);
        dp[x] = 1;
    }
    for (auto it = a.begin(); it != a.end(); it++)
    {
        for (int d = *it; d <= n; d += *it)
        {
            if (dp[d / *it] != INT_MAX) dp[d] = min(dp[d], dp[d / *it] + 1);
        }
    }
    for (int i = 1; i < n + 1; i ++)
    {
        if (dp[i] == INT_MAX) dp[i] = -1;
        cout << dp[i] << " ";
    }
    cout << endl;
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
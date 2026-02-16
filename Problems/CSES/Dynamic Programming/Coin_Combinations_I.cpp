#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n; int x;
    cin >> n >> x;
    vector<int> c(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> c[i];
    }
    vector<int> dp(x + 1, 0); // no. of ways to get x
    dp[0] = 1;
    for (int i = 1; i <= x; i ++)
    {
        for (int j : c)
        {
            if (i - j >= 0) dp[i] = (dp[i] + dp[i - j]) % 1000000007;
        }
    }
    cout << dp[x] % 1000000007 << endl;
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
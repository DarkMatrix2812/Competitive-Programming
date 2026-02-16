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
    vector<int> dp(x + 1, 0); // no. of ways to get x (distinct)
    dp[0] = 1;
    for (int i : c)
    {
        for (int j = i; j <= x; j ++)
        {
            if (j - i >= 0) dp[j] = (dp[j] + dp[j - i]) % 1000000007;
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
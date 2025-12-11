#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<vector<char>> obstacleGrid(n, vector<char>(n));
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            cin >> obstacleGrid[i][j];
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[n - 1][n - 1] = (obstacleGrid[n - 1][n - 1] == '*' ? 0 : 1);
    for (int i = n - 1; i >= 0; i --)
    {
        for (int j = n - 1; j >= 0; j --)
        {
            if (i == n - 1 && j == n - 1) continue;
            if (obstacleGrid[i][j] == '*') 
            {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = (dp[i][j + 1] + dp[i + 1][j]) % 1000000007;
        }
    }
    cout << dp[0][0] % 1000000007;
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
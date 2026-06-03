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
    map<int, int> freq;
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
        freq[a[i]] += 1;
    }
    int m = *max_element(a.begin(), a.end());
    vector<int> dp(m + 1);
    dp[0] = 0; dp[1] = freq[1];
    for (int i = 2; i < m + 1; i ++) // Bottom-up dp
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + i * freq[i]);
    }
    cout << dp[m];
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
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
    vector<bool> removed(n + 1, false);
    int ans = 0;
    for (int k = 1; k <= n; k++)
    {
        for (int m = k; m <= n; m += k)
        {
            // we basically try to delete multiple factors for the same small k, greedy approach
            if (removed[m]) continue;
            if (s[m - 1] == '1') break;               
            ans += k;
            removed[m] = true;
        }
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
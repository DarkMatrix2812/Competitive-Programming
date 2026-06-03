#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
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
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; i ++) // prefix sum
    {
        prefix[i] = prefix[i - 1] + a[i - 1];
    }
    int ans = 0;
    for (int i = 0; i < n; i ++)
    {
        for (int j = i + 1; j <= n; j ++)
        {
            ans = max(ans, (prefix[j] - prefix[i]) / (j - i));
        }
    }
    cout << ans << endl;
}
int main() 
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
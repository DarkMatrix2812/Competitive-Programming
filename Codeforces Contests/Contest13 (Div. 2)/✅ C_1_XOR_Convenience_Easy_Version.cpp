#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> ans(n + 1);
    // p_i ^ i = p_j => p_i = i ^ 1 => p_j = 1 (last element)
    ans[n] = 1;
    for (int i = 2; i <= n - 1; i ++)
    {
        ans[i] = i ^ 1; 
    }
    ans[1] = (n % 2 == 0 ? n : n - 1);
    for (int i = 1; i <= n; i ++)
    {
        cout << ans[i] << " ";
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
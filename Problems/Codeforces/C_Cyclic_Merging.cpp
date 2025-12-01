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
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    int ans = 0;
    int m = *max_element(a.begin(), a.end());
    for (int i = 0; i < n - 1; i ++)
    {
        ans += max(a[i], a[i + 1]);
    }
    ans += max(a[0], a[n - 1]);
    cout << ans - m << endl; //we subtract m,  becase we counted it twice instead of once - the max. element will remain at the end
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
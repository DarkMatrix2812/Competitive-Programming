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
    int ans = a[0]; int curr = 0;
    for (int i = 0; i < n; i ++)
    {
        curr += a[i];
        if (curr < 0)
        {
            ans = max(ans, curr);
            curr = 0;
            continue;
        }
        else ans = max(ans, curr);
    }
    cout << ans << endl;
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
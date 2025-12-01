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
    int sum = accumulate(a.begin(), a.end(), 0LL);
    int ans = LLONG_MAX;
    for (int i = 0; i < 1LL << n; i ++) 
    {
        int s = 0;
        int tmp = i;
        for (int j = 0; j < n; j ++) 
        {
            if (tmp % 2 == 1) s += a[j];
            tmp /= 2;
        }
        ans = min(ans, llabs(sum - 2 * s));
    }

    cout << ans;
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
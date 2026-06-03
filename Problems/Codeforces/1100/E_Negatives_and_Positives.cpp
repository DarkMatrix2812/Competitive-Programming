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
    int mn = INT_MAX; int sum = 0; int neg = 0;
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
        if (a[i] < 0) neg += 1;
        sum += abs(a[i]);
        mn = min(mn, abs(a[i]));
    }
    if (neg % 2 == 1) cout << sum - 2 * mn << endl;
    else cout << sum << endl;
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
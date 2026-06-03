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
    int s = 0;
    for (int i = 0; i + 1 < n; i ++)
    {
        s += abs(a[i] - a[i + 1]);
    }
    int saved = 0;
    saved = max(max(saved, abs(a[0] - a[1])), abs(a[n - 1] - a[n - 2]));
    for (int i = 1; i + 1 < n; i ++) 
    {
        saved = max(saved, abs(a[i - 1] - a[i]) + abs(a[i] - a[i + 1]) - abs(a[i - 1] - a[i + 1]));
    }
    cout << s - saved << endl;
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
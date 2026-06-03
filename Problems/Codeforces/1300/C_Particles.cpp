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
    int s1 = 0; int s2 = 0;
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
        if (i % 2 == 0) s1 += max(0LL, a[i]);
        else s2 += max(0LL, a[i]);
    }
    if (*max_element(a.begin(), a.end()) <= 0) cout << *max_element(a.begin(), a.end()) << endl;
    else cout << max(s1, s2) << endl;
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
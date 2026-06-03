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
    vector<int> pref_neg(n + 1);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
        pref_neg[i + 1] = pref_neg[i] + (a[i] < 0 ? 1 : 0);
    }
    int x = 0; int y = 0;
    for (int i = 1; i < n + 1; i ++)
    {
        if (pref_neg[i] % 2 == 0) x += 1;
        else y += 1;
    }
    cout << (n * (n + 1) / 2) - (x * (x - 1) / 2 + y * (y - 1) / 2 + x) << " " << (x * (x - 1) / 2 + y * (y - 1) / 2 + x) << endl;
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
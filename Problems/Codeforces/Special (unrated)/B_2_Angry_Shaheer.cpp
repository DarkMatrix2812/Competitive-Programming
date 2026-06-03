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
    if (accumulate(a.begin(), a.end(), 0LL) > 5 * n * (n + 1) / 2) cout << "SHAHEER";
    else if (accumulate(a.begin(), a.end(), 0LL) < 5 * n * (n + 1) / 2) cout << "FARAZ";
    else cout << "TIE";
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
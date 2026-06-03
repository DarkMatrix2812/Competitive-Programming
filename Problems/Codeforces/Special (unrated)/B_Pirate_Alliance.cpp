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
    int S = 0;
    for (int b = 0; b <= 31; b++)
    {
        int c = 0;
        int cand = 1LL << b;
        for (int i : a)
        {
            if (i & cand) c += 1;
        }
        if (c >= 2) S |= cand;
    }
    cout << S << endl;
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
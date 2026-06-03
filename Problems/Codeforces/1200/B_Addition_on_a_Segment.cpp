#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> b(n);
    int s = 0; int c = 0;
    for (int i = 0; i < n; i ++)
    {
        cin >> b[i];
        s += b[i];
        if (b[i] != 0) c += 1;
    }
    cout << min(s - n + 1, c) << endl;
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
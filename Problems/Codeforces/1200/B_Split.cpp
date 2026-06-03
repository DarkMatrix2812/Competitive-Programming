#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(2 * n);
    map<int, int> freq;
    for (int i = 0; i < 2 * n; i ++)
    {
        cin >> a[i];
        freq[a[i]] += 1;
    }
    int x = 0;
    int y = 0; int z = 0;
    for (auto &i : freq)
    {
        if (i.second % 2 == 1) x += 1;
        else if (i.second % 4 == 2) y += 1;
        else z += 1;
    }
    if (x > 0) cout << x + y * 2 + z * 2 << endl;
    else cout << x + y * 2 + (z / 2) * 4 << endl;
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
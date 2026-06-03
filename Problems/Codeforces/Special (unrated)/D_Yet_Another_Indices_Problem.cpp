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
    int z = 0; int o = 0; int t = 0;
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
        if (a[i] % 3 == 0) z += 1;
        else if (a[i] % 3 == 1) o += 1;
        else t += 1;
    }
    cout << z * (z - 1) / 2 + o * t;

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
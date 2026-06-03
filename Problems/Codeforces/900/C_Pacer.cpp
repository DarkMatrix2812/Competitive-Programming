#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <numeric>
using ll = long long;
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    int prev_a = 0; int prev_b = 0;
    ll ans = 0;
    for (int i = 0; i < n; i ++)
    {
        int a, b;
        cin >> a >> b;
        if (((a + b) % 2) == ((prev_a + prev_b) % 2))
        {
            ans += (a - prev_a);
            prev_a = a; prev_b = b;
        }
        else 
        {
            ans += (a - prev_a - 1);
            prev_a = a; prev_b = b;
        }
    }
    if (prev_a != m) ans += (m - prev_a);
    cout << ans << endl;
}
int main() 
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
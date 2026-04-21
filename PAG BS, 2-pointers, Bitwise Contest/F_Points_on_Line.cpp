#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve()
{
    int n; int d;
    cin >> n >> d;
    vector<int> x(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> x[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; i ++)
    {
        int stop = upper_bound(x.begin(), x.end(), x[i] + d) - x.begin() - 1;
        ll count = stop - i;
        if (count >= 2)
        {
            ans += (count * (count - 1)) / 2;
        }
    }
    cout << ans << endl;
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) 
    {
        solve();
    }
}
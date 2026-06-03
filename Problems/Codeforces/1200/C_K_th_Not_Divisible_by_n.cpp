#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve()
{
    ll n; int k;
    cin >> n >> k;
    ll start = 1; ll stop = n * k;
    ll ans = 0;
    while (start <= stop)
    {
        ll mid = start + (stop - start) / 2;
        ll count = mid - mid / n;
        if (count >= k)
        {
            ans = mid;
            stop = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
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
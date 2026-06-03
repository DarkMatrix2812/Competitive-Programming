#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int nb, ns, nc;
    cin >> nb >> ns >> nc;
    int pb, ps, pc;
    cin >> pb >> ps >> pc;
    ll r;
    cin >> r;
    ll low = 0, high = 1e13, ans = 0;
    while (low <= high)
    {
        ll mid = (low + high) / 2;
        ll req_b = max(0LL, mid * (ll)(count(s.begin(), s.end(), 'B')) - nb);
        ll req_s = max(0LL, mid * (ll)(count(s.begin(), s.end(), 'S')) - ns);
        ll req_c = max(0LL, mid * (ll)(count(s.begin(), s.end(), 'C')) - nc);
        ll cost = req_b * pb + req_s * ps + req_c * pc;
        if (cost <= r)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << ans << '\n';
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
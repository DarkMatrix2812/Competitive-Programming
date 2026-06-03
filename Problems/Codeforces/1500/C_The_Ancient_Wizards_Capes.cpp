#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve()
{
    ll MOD = 676767677;
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) 
    {
        cin >> a[i];
    }
    vector<int> b(n + 1);
    for (int i = 1; i <= n; ++i) 
    {
        b[i] = a[i] - (n - i + 1);
    }
    auto valid = [&](int L) -> bool 
    {
            if (L < 0 || L > n) 
            return false;
            int prev = 0;
            for (int i = 1; i <= n; ++i) 
            {
                int pi = L + b[i] - prev;
                int xi = pi - prev;
                if (xi != 0 && xi != 1) 
                return false;
                if (pi < 0 || pi > i) 
                return false;
                prev = pi;
            }
            return prev == L;
    };
    ll ans = 0;
    int c1 = -b[1];
    int c2 = 1 - b[1];
    if (valid(c1)) 
    ans += 1;
    if (c2 != c1 && valid(c2)) 
    ans += 1;
    cout << ans % MOD << "\n";
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
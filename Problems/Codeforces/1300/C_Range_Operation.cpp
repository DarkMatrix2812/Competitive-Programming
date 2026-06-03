#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i < n + 1; i ++)
    {
        cin >> a[i];
    }
    vector<int> pref(n + 1);
    pref[0] = 0;
    for (int i = 1; i < pref.size(); i ++)
    {
        pref[i] = pref[i - 1] + a[i];
    }
    vector<int> L(n+1), R(n+1);
    for(int l = 1; l <= n; l ++)
    {
        L[l] = -(l * l) + l + pref[l - 1];
    }
    for(int r = 1; r <= n; r ++)
    {
        R[r] = r * r + r - pref[r];
    }
    int gain = 0;
    int best = LLONG_MIN;
    for(int i = 1; i <= n; i ++)
    {
        gain = max(gain, L[i]); //we try to maximize gain of (only L part)
        best = max(best, R[i] + gain); //we try to maxmize best gain (total L + R)
    }
    cout << pref[n] + best << "\n";
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
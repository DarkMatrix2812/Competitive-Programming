#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }
    map<ll, ll> count;
    for (int i = 0; i < n; i++) 
    {
        count[a[i]]++;
    }
    ll base = 0;
    vector<ll> odd, even;
    for (auto& pair : count) 
    {
        base += pair.first * (pair.second / 2);
        if (pair.second % 2 == 1) 
        {
            odd.push_back(pair.first);
        } 
        else if (pair.second >= 2) 
        {
            even.push_back(pair.first);
        }
    }
    if (base == 0) 
    {
        cout << 0 << endl;
        return;
    }
    ll ans = 0;
    for (ll i : odd) 
    {
        if (2 * base > i) 
        {
            ans = max(ans, 2 * base + i);
        }
    }
    for (ll i = 1; i < odd.size(); i++) 
    {
        if (odd[i - 1] + 2 * base > odd[i]) 
        {
            ans = max(ans, odd[i - 1] + 2 * base + odd[i]);
        }
    }
    for (ll i : even) 
    {
        if (base > i) 
        {
            ans = max(ans, 2 * base);
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
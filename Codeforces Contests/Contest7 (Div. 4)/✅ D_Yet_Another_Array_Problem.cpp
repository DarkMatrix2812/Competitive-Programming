#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll gcd(ll a, ll b) {

    while (b != 0) 
    {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    ll g = a[0];
    for (int i = 1; i < n; i++) 
    {
        g = gcd(g, a[i]);
    }
    if (g == 1) 
    {
        cout << 2 << endl;
        return;
    }
    for (ll p = 2 ;; p++) 
    {
        bool isPrime = true;
        for (ll i = 2; i * i <= p; ++i)
        {
            if (p % i == 0) 
            { 
                isPrime = false; 
                break; 
            }
        }
        if (!isPrime) continue;
        if (gcd(g, p) == 1) 
        {
            cout << p << endl;
            return;
        }
    }
    cout << -1 << endl;
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
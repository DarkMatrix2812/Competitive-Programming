#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
bool isPrime(ll n) 
{
    if (n <= 1) return false;
    for (ll i = 2; i * i <= n; i++) 
    {
        if (n % i == 0) return false;
    }
    return true;
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> nums(n);
    for (ll i = 0; i < n; i ++)
    {
        cin >> nums[i];
    }
    for (ll i : nums)
    {
        if (sqrt(i) == ceil(sqrt(i)) && isPrime(ceil(sqrt(i))))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
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
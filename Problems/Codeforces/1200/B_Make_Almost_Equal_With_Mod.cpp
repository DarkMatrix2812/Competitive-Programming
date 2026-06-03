#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int gcd(int a, int b)
{
    return (!b ? a : gcd(b, a % b));
}
void solve()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> arr[i];
    }
    ll even_count = 0; ll odd_count = 0;
    for (ll i : arr)
    {
        if (i % 2 == 0)
        {
            even_count += 1;
        }
        else
        {
            odd_count += 1;
        }
    }
    sort(arr.begin(), arr.end());
    if (odd_count == 0 || even_count == 0)
    {
        ll g = arr[1] - arr[0];
        for (int i = 2; i < n; i ++)
        {
            g = gcd(g, arr[i] - arr[i - 1]);
        }
        cout << 2 * g << endl;
        return;
    }
    cout << 2 << endl;
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
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
int gcd(int a, int b) 
{
    return b == 0 ? a : gcd(b, a % b);
}
void solve()
{
    int a, b;
    cin >> a >> b;
    int g = gcd(a, b);
    if (a == g || b == g) cout << "YES";
    else cout << "NO";
}
int32_t main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) 
    {
        solve();
    }
}
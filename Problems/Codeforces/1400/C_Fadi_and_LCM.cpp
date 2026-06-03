#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
int gcd(int a, int b) 
{
    if (b == 0) 
    {
        return a;
    }
    return gcd(b, a % b);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> factors;
    pair<int, int> ans;
    int mn = n;
    for (int i = 1; i * i <= n; ++i) 
    {
        if (n % i == 0) 
        {
            if (gcd(i, n / i) == 1) 
            {
                if (max(i, n / i) <= mn) 
                {
                    ans = {i, n / i};
                    mn = max(i, n / i);
                }
            }
        }
    }
    cout << ans.first << " " << ans.second << endl;
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
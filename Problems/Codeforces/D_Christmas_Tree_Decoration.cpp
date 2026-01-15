#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353;
int fact(int n) 
{
    int res = 1;
    for (int i = 1; i <= n; i ++)
        res = res * i % MOD;
    return res;
}
int C[55][55];
void nCr() 
{
    for (int i = 0; i <= 50; i++) 
    {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j ++) 
        {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    int box0;
    cin >> box0;
    vector<int> a(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    int s = box0 + accumulate(a.begin(), a.end(), 0LL);
    int k = s / n;
    sort(a.rbegin(), a.rend());
    vector<int> tmp(n, k);
    for (int i = 0; i < s % n; i ++)
    {
        tmp[i] += 1;
    }
    int ans = 1;
    for (int i = 0; i < n; i ++)
    {
        int c = 0;
        for (int j = 0; j < n; j ++)
        {
            if (a[i] <= tmp[j])
            {
                if (c == 0) tmp[j] = -1;
                c += 1;
            }
        }
        ans = ans * c % 998244353;
    }
    cout << ans % 998244353 << endl;
}
int32_t main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    nCr();
    while (t--) 
    {
        solve();
    }
}   
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> ans(n + 1, 0);
    vector<vector<int>> v;
    for (int i = 0; i < q; i ++)
    {
        int c, l , r;
        cin >> c >> l >> r;
         v.push_back({c, l, r});
    }
    vector<int> min;
    vector<int> mex;
    for (vector<int> x : v)
    {
        if (x[0] == 1)
        {
            for (int i = x[1]; i <= x[2]; i ++)
            {
                min.push_back(i);
            }
        }
        if (x[0] == 2)
        {
            for (int i = x[1]; i <= x[2]; i ++)
            {
                mex.push_back(i);
            }
        }
    }
    for (int i : min)
    {
        if (find(mex.begin(), mex.end(), i) != mex.end())
        {
            ans[i] = k + 1;
        }
        else
        {
            ans[i] = k;
        }
    }
    for (int i : mex)
    {
        if (find(min.begin(), min.end(), i) != min.end())
        {
            ans[i] = k + 1;
        }
        else
        {
            ans[i] = i % k;
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        cout << ans[i] <<  " ";
    }
    cout << endl;
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
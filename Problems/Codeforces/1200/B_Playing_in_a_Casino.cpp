#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < m; j ++)
        {
            cin >> v[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i ++)
    {
        vector<int> tmp;
        for (int j = 0; j < n; j ++)
        {
            tmp.push_back(v[j][i]);
        }
        sort(tmp.begin(), tmp.end());
        int x = tmp.size();
        if (x % 2 == 0)
        {
            int l = 0; int r = x - 1;
            for (int k = 0; k < tmp.size() / 2; k ++)
            {
                ans += (x - 1) * (tmp[r] - tmp[l]);
                l ++; r --; x -= 2;
            }
        }
        else
        {
            int l = 0; int r = x - 1;
            for (int k = 0; k < tmp.size() / 2; k ++)
            {
                ans += (x - 1) * (tmp[r] - tmp[l]);
                l ++; r --; x -= 2;
            }
        }
    }
    cout << ans << endl;
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
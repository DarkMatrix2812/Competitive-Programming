#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i ++)
    {
        int b;
        cin >> b;
        a[i] = {b % y, b % x};
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n;)
    {
        int j = i;
        vector<int> v;
        // we need a_i congruent to a_j (mod y)
        while (j < n && a[j].first == a[i].first)
        {
            v.push_back(a[j].second);
            j += 1;
        }
        if (v.size() >= 2)
        {
            sort(v.begin(), v.end());
            // count pairs where both are 0
            int cnt0 = 0;
            while (cnt0 < v.size() && v[cnt0] == 0) 
            {
                cnt0 += 1;
            }
            ans += cnt0 * (cnt0 - 1) / 2;
            // count pairs where sum = x
            int l = cnt0;
            int r = v.size() - 1;
            while (l < r)
            {
                int sum = v[l] + v[r];
                if (sum == x)
                {
                    if (v[l] == v[r])
                    {
                        int cnt = r - l + 1;
                        ans += cnt * (cnt - 1) / 2;
                        break;
                    }
                    int c1 = 1, c2 = 1;
                    while (l + 1 < r && v[l] == v[l + 1]) 
                    {
                        c1 += 1;
                        l += 1;
                    }
                    while (r - 1 > l && v[r] == v[r - 1]) 
                    {
                        c2 += 1;
                        r -= 1;
                    }
                    ans += c1 * c2;
                    l += 1;
                    r -= 1;
                }
                else if (sum < x) l += 1;
                else r -= 1;
            }
        }
        i = j;
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
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n; 
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> x[i];
    }
    int q;
    cin >> q;
    vector<int> m(q);
    for (int i = 0; i < q; i ++)
    {
        cin >> m[i];
    }
    sort(x.begin(), x.end());
    for (int i : m)
    {
        int start = 0; int stop = n - 1;
        int ans = -1;
        while (start <= stop)
        {
            int mid = start + (stop - start) / 2;
            if (x[mid] <= i)
            {
                ans = mid;
                start = mid + 1;
            }
            else
            {
                stop = mid - 1;
            }
        }
        cout << ans + 1 << endl;
    }
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
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
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    vector<double> d(n - 1);
    for (int i = 0; i < n - 1; i ++) 
    {
        d[i] = x[i + 1] - x[i];
    }
    int ans = 0;
    // min and max values for r[i]
    double min_r = 0.0;
    double max_r = d[0];
    for (int i = 0; i < d.size(); i ++) 
    {
       // r[i] + r[i + 1] = d[i] for tangency
       // min and max values for r[i + 1]
        double next_min = max(d[i] - max_r, 0.0); // ensuring radius always positive
        double next_max = d[i] - min_r;
        // also ensure r[i + 1] < dist[i + 1]
        if (i + 1 < d.size()) 
        {
            next_max = min(next_max, d[i + 1]);
        }
        // check if we can extend tangent chain
        if (next_min < next_max) 
        {
            ans += 1;
            min_r = next_min;
            max_r = next_max;
        } 
        // else, must start new chain - reset all values
        else 
        {
            min_r = 0.0;
            if (i + 1 < d.size()) 
            {
                max_r = d[i + 1];
            }
        }
    }
    cout << ans << "\n";
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
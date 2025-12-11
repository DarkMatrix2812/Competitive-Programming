#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> x(n), b(n);
    vector<array<int, 3>> v(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> x[i];
    }
    for (int i = 0; i < n; i ++)
    {
        cin >> b[i];
        v[i] = {x[i], b[i], i};
    }
    sort(v.begin(), v.end());
    vector<int> ans(n);
    vector<int> pref(n + 1, 0);
    for(int i = 0; i < n; i++)
    {
        pref[i+1] = pref[i] + v[i][0];
    }
    for(int i = 0; i < n; i ++)
    {
        int x = v[i][0], b = v[i][1];
        vector<int> Lcost, Rcost;
        Lcost.push_back(0);
        Rcost.push_back(0);
        int cost = 0;
        // left costs
        for(int l = i - 1; l >= 0; l --)
        {
            cost += (x - v[l][0]);
            Lcost.push_back(cost);
            if(cost > b) break;
        }
        cost = 0;
        // right costs
        for(int r = i + 1; r < n; r ++) 
        {
            cost += (v[r][0] - x);
            Rcost.push_back(cost);
            if(cost > b) break;
        }
        int best = 0;
        // for each #left, find max #right
        for(int k = 0; k < Lcost.size(); k ++)
        {
            if(Lcost[k] > b) break;
            int rem = b - Lcost[k];
            int t = upper_bound(Rcost.begin(), Rcost.end(), rem) - Rcost.begin() - 1;
            best = max(best, k + t);
        }
        ans[v[i][2]] = best;
    }

    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
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
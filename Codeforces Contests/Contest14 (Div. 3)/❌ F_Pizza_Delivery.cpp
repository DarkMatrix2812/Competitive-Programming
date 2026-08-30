#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, Ax, Ay, Bx, By;
    cin >> n >> Ax >> Ay >> Bx >> By;
    vector<int> x(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> x[i];
    }
    vector<int> y(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> y[i];
    }
    vector<pair<int, int>> coord(n);
    for (int i = 0; i < n; i ++)
    {
        coord[i] = {x[i], y[i]};
    }
    sort(coord.begin(), coord.end());
    int dx = Bx - Ax;
    // minimize y distance
    map<int, vector<int>> group;
    for (auto &p : coord)
    {
        group[p.first].push_back(p.second);
    }
    vector<pair<int,int>> intervals;
    for (auto &p : group)
    {
        auto &v = p.second;
        sort(v.begin(), v.end());
        intervals.push_back({v[0], v.back()});
    }
    int L = intervals[0].first;
    int R = intervals[0].second;
    int dp0 = abs(Ay - R) + (R - L); // end at L
    int dp1 = abs(Ay - L) + (R - L); // end at R
    for (int i = 1; i < intervals.size(); i ++)
    {
        int tmpL = intervals[i].first;
        int tmpR = intervals[i].second;
        int tmp0 = min(dp1 + abs(R - tmpR) + tmpR - tmpL, dp0 + abs(L - tmpR) + tmpR - tmpL); // end at L
        int tmp1 = min(dp0 + abs(L - tmpL) + tmpR - tmpL, dp1 + abs(R - tmpL) + tmpR - tmpL); // end at R
        dp0 = tmp0;
        dp1 = tmp1;
        L = tmpL;
        R = tmpR;
    }
    int dy = min(dp0 + abs(L - By), dp1 + abs(R - By));
    cout << dx + dy << endl;
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
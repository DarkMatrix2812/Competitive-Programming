#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, k, q;
    cin >> n >> k >> q;
    vector<pair<int, int>> recipe;
    for (int i = 0; i < n; i ++)
    {
        int l, r;
        cin >> l >> r;
        recipe.push_back({l, r});
    }
    vector<pair<int, int>> query;
    for (int i = 0; i < q; i ++)
    {
        int a, b;
        cin >> a >> b;
        query.push_back({a, b});
    }
    vector<int> diff(2e5 + 2, 0);
    for (auto &p : recipe)
    {
        diff[p.first] += 1;
        diff[p.second + 1] -= 1;
    }
    vector<int> pref1(2e5 + 1, 0);
    for (int i = 1; i <= 2e5; i ++)
    {
        pref1[i] = pref1[i - 1] + diff[i];
    }
    vector<int> valid(2e5 + 1, 0);
    for (int i = 1; i <= 2e5; i ++)
    {
        if (pref1[i] >= k) valid[i] = 1;
    }
    vector<int> pref2(2e5 + 1, 0);
    for (int i = 1; i <= 2e5; i ++)
    {
        pref2[i] = pref2[i - 1] + valid[i];
    }
    for (auto &p : query)
    {
        cout << pref2[p.second] - pref2[p.first - 1] << endl;
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
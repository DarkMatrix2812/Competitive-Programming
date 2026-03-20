#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
int func(const vector<int>& a)
{
    int sum = 0, sumsq = 0;
    for (int x : a) {
        sum += x;
        sumsq += (x * x);
    }
    return (sum * sum - sumsq) / 2;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    vector<array<int,3>> all;
    for (int i = 0; i <= n - 3; i ++)
    {
        all.push_back({a[i], a[i+1], a[i+2]});
    }
    map<pair<int, int>, map<int, int>> f1;
    map<pair<int, int>, map<int, int>> f2;
    map<pair<int, int>, map<int, int>> f3;
    for (array<int, 3> v : all)
    {
        f1[{v[0], v[1]}][v[2]] += 1;
        f2[{v[1], v[2]}][v[0]] += 1;
        f3[{v[0], v[2]}][v[1]] += 1;
    }
    int ans = 0;
    for (auto &p : f1) 
    {
        vector<int> freq;
        for (auto &q : p.second) 
        {
            freq.push_back(q.second);
        }
        ans += func(freq);
    }
    for (auto &p : f2) 
    {
        vector<int> freq;
        for (auto &q : p.second) 
        {
            freq.push_back(q.second);
        }
        ans += func(freq);
    }
    for (auto &p : f3) 
    {
        vector<int> freq;
        for (auto &q : p.second) 
        {
            freq.push_back(q.second);
        }
        ans += func(freq);
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
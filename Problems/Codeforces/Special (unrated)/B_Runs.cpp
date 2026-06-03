#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    set<char> distinct;
    map<char, int> f;
    for (char c : s)
    {
        distinct.insert(c);
        f[c] += 1;
    }
    if (distinct.size() > m || (distinct.size() == 1 && m != 1))
    {
        cout << "NO" << endl;
        return;
    }
    if (distinct.size() == 1 && m == 1)
    {
        cout << "YES" << endl;
        return;
    }
    vector<int> v;
    for (auto p : f)
    {
        v.push_back(p.second);
    }
    if (m <= min(n, 2 * (n - *max_element(v.begin(), v.end())) + 1)) cout << "YES" << endl;
    else cout << "NO" << endl;
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
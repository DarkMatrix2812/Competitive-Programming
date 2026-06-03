#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> p[i];
    }
    string x;
    cin >> x;
    //first, we note that we cannot make the position of 1 or n into '1' or if the end of the string x is '1' - then also impossible
    //this is due to the strict equality condition (no <= or >= allowed)
    if (x[0] == '1' || x[x.length() - 1] == '1')
    {
        cout << -1 << endl;
        return;
    }
    int index_1 = 0; int index_n = 0;
    for (int i = 0; i < n; i ++)
    {
        if (p[i] == 1) index_1 = i;
        if (p[i] == n) index_n = i;
    }
    if (x[index_1] == '1' || x[index_n] == '1')
    {
        cout << -1 << endl;
        return;
    }
    string s(n, '0');
    int ans = 0;
    //Now, we just ensure that s is '1111...' (except at the positions excluded before) - that simply satisfies the question's condition
    vector<pair<int, int>> v;
    if (1 <= index_1 + 1)
    {
        ans += 1;
        v.push_back(make_pair(1, index_1 + 1));
    }
    if (1 <= index_n + 1)
    {
        ans += 1;
        v.push_back(make_pair(1, index_n + 1));
    }
    if (index_1 <= index_n)
    {
        ans += 1;
        v.push_back(make_pair(index_1 + 1, index_n + 1));
    }
    if (index_n <= index_1)
    {
        ans += 1;
        v.push_back(make_pair(index_n + 1, index_1 + 1));
    }
    if (index_1 + 1 <= n)
    {
        ans += 1;
        v.push_back(make_pair(index_1 + 1, n));
    }
    if (index_n + 1 <= n)
    {
        ans += 1;
        v.push_back(make_pair(index_n + 1, n));
    }
    cout << ans << endl;
    for (auto p : v)
    {
        cout << p.first << " " << p.second << endl;
    }
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
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i ++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    while (!s.count(s.size()))
    {
        s.insert(s.size());
    }
    cout << s.size() << endl;
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
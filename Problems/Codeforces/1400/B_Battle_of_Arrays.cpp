#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    multiset<int> a, b;
    for (int i = 0; i < n; i ++)
    {
        int x;
        cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < m; i ++)
    {
        int x;
        cin >> x;
        b.insert(x);
    }
    int turn = 1;
    while (!a.empty() && !b.empty())
    {
        if (turn % 2 == 1)
        {
            int x = *a.rbegin();
            int y = *b.rbegin();
            if (y <= x) b.erase(prev(b.end()));
            else
            {
                b.erase(prev(b.end()));
                b.insert(y - x);
            }
        }
        else
        {
            int x = *b.rbegin();
            int y = *a.rbegin();
            if (y <= x) a.erase(prev(a.end()));
            else
            {
                a.erase(prev(a.end()));
                a.insert(y - x);
            }
        }
        turn += 1;
    }
    if (a.empty()) cout << "Bob" << endl;
    else cout << "Alice" << endl;
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
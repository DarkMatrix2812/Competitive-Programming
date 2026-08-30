#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve()
{
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> a(n);
    vector<int> b(m); vector<int> c(m);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i ++)
    {
        cin >> b[i] >> c[i];
    }
    vector<int> original = a;
    vector<int> changed;
    vector<bool> seen(n, false);
    for (int i = 0; i < m; i ++)
    {
        if (!seen[b[i] - 1])
        {
            seen[b[i] - 1] = true;
            changed.push_back(b[i] - 1);
        }
        a[b[i] - 1] += c[i];
        if (a[b[i] - 1] > h)
        {
            for (int x : changed)
            {
                a[x] = original[x];
                seen[x] = false;
            }
            changed.clear();
        }
    }
    for (int i : a)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main() 
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
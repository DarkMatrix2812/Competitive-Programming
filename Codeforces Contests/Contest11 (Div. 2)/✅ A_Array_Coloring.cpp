#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    vector<int> tmp = a;
    bool ok = true;
    map<int, string> color;
    for (int i = 0; i < n; i ++)
    {
        if (i % 2 == 0) color[a[i]] = "r";
        else color[a[i]] = "b";
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i ++)
    {
        if (color[a[i]] == color[a[i - 1]]) 
        {
            ok = false;
            break;
        }
    }
    for (int i = 0; i < n; i ++)
    {
        if (i % 2 == 0) color[tmp[i]] = "b";
        else color[tmp[i]] = "r";
    }
    sort(tmp.begin(), tmp.end());
    for (int i = 1; i < n; i ++)
    {
        if (color[tmp[i]] == color[tmp[i - 1]]) 
        {
            ok = false;
            break;
        }
    }
    if (ok == true) cout << "YES" << endl;
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
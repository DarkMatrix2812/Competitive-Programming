#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve()
{
    int n; int k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> v[i];
    }
    vector<int> tmp = v;
    sort(tmp.begin(), tmp.end());
    if (tmp == v)
    {
        cout << "YES" << endl;
    }
    else
    {
        if (k < 2)
        cout << "NO" << endl;
        else
        cout << "YES" << endl;
    }
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

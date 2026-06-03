#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<string> a(n);
    string s = "";
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
        if (s + a[i] < a[i] + s) s = s + a[i];
        else s = a[i] + s;
    }
    cout << s << endl;
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
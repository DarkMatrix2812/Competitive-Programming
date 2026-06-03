#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    set<string> ans;
    string x;
    cin.ignore();
    for (int i = 0; i < n; i ++)
    {
        getline(cin, x);
        ans.insert(x);
    }
    cout << ans.size() << endl;
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
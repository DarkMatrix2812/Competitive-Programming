#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    map<string, int> cnt;
    for (int i = 0; i < n; i ++)
    {
        string s;
        cin >> s;
        if (cnt[s]) cout << s << cnt[s] << endl;
        else cout << "OK" << endl;
        cnt[s] += 1;
    }
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
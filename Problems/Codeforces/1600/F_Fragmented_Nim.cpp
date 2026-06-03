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
    int cnt = 0;
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
        if (a[i] == 1) cnt += 1;
    }
    if (n == 1)
    {
        cout << "Alice" << endl;
        return;
    }
    if (cnt == n) // all 1's edge case
    {
        if (cnt % 2 == 0) cout << "Bob" << endl;
        else cout << "Alice" << endl;
        return;
    }
    if (cnt % 2 == 0) cout << "Alice" << endl;
    else cout << "Bob" << endl;
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
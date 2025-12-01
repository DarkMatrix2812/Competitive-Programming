#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    vector<int> a(3);
    for (int i = 0; i < 3; i ++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a.back() - a[0] >= 10)
    {
        cout << "check again" << endl;
    }
    else
    {
        cout << "final " << a[1] << endl;
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
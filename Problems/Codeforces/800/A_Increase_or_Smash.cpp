#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve()
{
    int n;
    cin >> n;
    set<ll> arr;
    int x;
    for (int i = 0; i < n; i ++)
    {
        cin >> x;
        arr.insert(x);
    }
    cout << 2 * arr.size() - 1 << endl;
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

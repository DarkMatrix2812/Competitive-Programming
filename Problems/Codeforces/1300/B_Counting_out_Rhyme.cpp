#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i ++)
    {
        cin >> a[i];
    }
    vector<int> v(n);
    for (int i = 0; i < n; i ++)
    {
        v[i] = i + 1;
    }
    auto curr = v.begin();
    for (int i = 0; i < k; i ++)
    {
        int idx = a[i] % v.size();
        int pos = (curr - v.begin() + idx) % v.size();
        curr = v.begin() + pos;
        cout << *curr << " ";
        curr = v.erase(curr);
        if (curr == v.end()) curr = v.begin();
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
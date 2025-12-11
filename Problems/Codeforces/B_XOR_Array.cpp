#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> pref(n + 1);
    pref[0] = 0;
    set<int> seen;
    seen.insert(0);
    int num = 1;
    for (int i = 1; i < n + 1; i ++)
    {
        if (i == r) 
        {
            pref[r] = pref[l - 1];
        }
        else
        {
            while (seen.count(num)) 
            {
                num += 1;
            }
            pref[i] = num;
            seen.insert(num);
        }
    }
    vector<int> ans(n);
    for (int i = 1; i < n + 1; i ++)
    {
        cout << (pref[i] ^ pref[i - 1]) << " ";
    }
    cout << endl;
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
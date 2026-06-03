#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    vector<int> pref_max(n);
    pref_max[0] = a[0];
    for (int i = 1; i < n; i ++)
    {
        pref_max[i] = max(pref_max[i - 1], a[i]);
    }
    vector<int> pref(n);
    pref[0] = a[0];
    for (int i = 1; i < n; i ++)
    {
        pref[i] = pref[i - 1] + a[i];
    }
    for (int i = 0; i < q; i ++)
    {
        int x;
        cin >> x;
        auto it = upper_bound(pref_max.begin(), pref_max.end(), x);
        if (it ==pref_max.begin())
        {
            cout << 0 << " ";
            continue;
        }
        it--;
        int idx = it - pref_max.begin();
        cout << pref[idx] << " ";
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
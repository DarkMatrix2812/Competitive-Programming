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
    vector<int> even; vector<int> odd;
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
        if (a[i] % 2 == 0) even.push_back(a[i]);
        else odd.push_back(a[i]);
    }
    if (odd.size() == 0 || even.size() == 0) 
    {
        cout << 0 << endl;
        return;
    }
    sort(even.begin(), even.end());
    int m1 = *max_element(odd.begin(), odd.end());
    int m2 = *max_element(even.begin(), even.end());
    int ans = 0;
    for (int i = 0; i < even.size(); i ++)
    {
        if (even[i] < m1)
        {
            m1 += even[i];
            ans += 1;
        }
        else
        {
            m1 += m2;
            ans += 2;
        }
    }
    cout << ans << endl;
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
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <numeric>
using ll = long long;
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> pref_max(n);
    pref_max[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        pref_max[i] = max(pref_max[i - 1], a[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (i % 2 == 0)
        {
            a[i - 1] = pref_max[i - 1];
            if (a[i - 1] <= a[i - 2])
            {
                ans += a[i - 2] - a[i - 1] + 1;
                a[i - 2] = a[i - 1] - 1;
            }
        }
        else
        {
            if (i != 1 && a[i - 1] >= a[i - 2])
            {
                ans += a[i - 1] - a[i - 2] + 1;
                a[i - 1] = a[i - 2] - 1;
            }
        }
    }
    cout << ans << endl;
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
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
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    vector<int> suffix_max(n);
    suffix_max[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i --)
    {
        suffix_max[i] = max(suffix_max[i + 1], a[i]);
    }
    for (int i = 0; i < n; i ++)
    {
        if (suffix_max[i] > a[i])
        {
            int r = i;
            for (int j = i; j < n; j ++)
            {
                if (a[j] == suffix_max[i])
                {
                    r = j;
                    break;
                }
            }
            reverse(a.begin() + i, a.begin() + r + 1);
            break;
        }
    }
    for (int i : a)
    {
        cout << i << " ";
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
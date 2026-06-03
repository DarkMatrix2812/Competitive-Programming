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
    vector<int> even;
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
        if (a[i] % 2 == 0) even.push_back(a[i]);
    }
    if (even.size() >= 2)
    {
        cout << even[0] << " " << even[1] << endl;
        return;
    }
    for (int i = 0; i < a.size(); i ++)
    {
        for (int j = i + 1; j < a.size(); j ++)
        {
            if ((a[j] % a[i]) % 2 == 0)
            {
                cout << a[i] << " " << a[j] << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
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
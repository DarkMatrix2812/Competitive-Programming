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
    if (a[0] == -1 && a.back() == -1)
    {
        cout << 0 << endl;
        for (int i : a)
        {
            if (i == -1) cout << 0 << " ";
            else cout << i << " ";
        }
        cout << endl;
    }
    else
    {
        if (a.back() == -1)
        {
            a.back() = a[0];
            cout << 0 << endl;
            for (int i : a)
            {
                if (i == -1) cout << 0 << " ";
                else cout << i << " ";
            }
            cout << endl;
        }
        else if (a[0] == -1)
        {
            a[0] = a.back();
            cout << 0 << endl;
            for (int i : a)
            {
                if (i == -1) cout << 0 << " ";
                else cout << i << " ";
            }
            cout << endl;
        }
        else
        {
            cout << abs(a[0] - a.back()) << endl;
            for (int i : a)
            {
                if (i == -1) cout << 0 << " ";
                else cout << i << " ";
            }
            cout << endl;
        }
    }
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
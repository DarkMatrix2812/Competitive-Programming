#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve()
{
    int n; int k;
    cin >> n >> k;
    if (k > n)
    {
        cout << "NO" << endl;
        return;
    }
    if (n % 2 != 0 && k % 2 == 0)
    {
        cout << "NO" << endl;
        return;
    }
    if (n % 2 == 0 && k % 2 != 0 && k > n / 2)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    if (n % 2 == 0 && k <= n / 2)
    {
        for (int i = 1; i < k; i ++)
        {
            cout << 2 << " ";
        }
        cout << n - 2 * (k - 1) << endl;
        return;
    }
    if (n % 2 == 0 && k > n / 2)
    {
        for (int i = 1; i < k; i ++)
        {
            cout << 1 << " ";
        }
        cout << n - (k - 1) << endl;
        return;
    }
    if (n % 2 != 0)
    {
        for (int i = 1; i < k; i ++)
        {
            cout << 1 << " ";
        }
        cout << n - (k - 1) << endl;
        return;
    }
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
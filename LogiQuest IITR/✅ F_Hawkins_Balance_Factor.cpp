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
    int d = 0;
    for (int i = 0; i < n; i ++) 
    {
        while (d <= i && a[i - d] >= d + 1) // Check if we can extend sequence to (d + 1), for that, the smallest
        // element in subsequence must be >= (d + 1)
        {
            d += 1;
        }
        cout << d << " ";
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
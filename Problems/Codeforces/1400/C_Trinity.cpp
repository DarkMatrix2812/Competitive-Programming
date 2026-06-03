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
    for (int i = 0; i < n ; i ++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int l = 0; int seq = 2;
    for (int r = 2; r < n; r ++)
    {
        while (r - l >= 2 && a[l] + a[l + 1] <= a[r])
        {
            l += 1;
        }
        seq = max(seq, r - l + 1); //just find the longest sequence which forms a valid triangle, ans is n - len(seq) because we
        // can replace other elements with elements in sequence
    }
    cout << n - seq << endl;
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
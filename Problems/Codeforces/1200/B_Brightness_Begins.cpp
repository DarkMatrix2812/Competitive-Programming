#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
int SQRT(int x) 
{
    if (x < 2) return x;
    int lo = 1, hi = x, ans = 1;
    while (lo <= hi) 
    {
        int mid = lo + (hi - lo) / 2;
        if (mid <= x / mid) 
        {  
            ans = mid;
            lo = mid + 1;
        } 
        else 
        {
            hi = mid - 1;
        }
    }
    return ans;
}
void solve()
{
    int k;
    cin >> k;
    int start = 1; int stop = LLONG_MAX; int ans = 0;
    while (start <= stop)
    {
        int mid = start + (stop - start) / 2;
        if (mid - SQRT(mid) == k)
        {
            ans = mid;
            stop = mid - 1;
        }
        else if (mid - SQRT(mid) > k)
        {
            stop = mid - 1;
        }
        else
        {
            start = mid + 1;
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
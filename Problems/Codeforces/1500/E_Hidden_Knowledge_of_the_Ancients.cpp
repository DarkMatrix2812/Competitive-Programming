#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, k, l, r;
    cin >> n >> k >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    vector<int> vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for(int i = 0; i < n; i++)
    {
        a[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
    }
    int M = vals.size();
    vector<int> freqK(M, 0), freqKm1(M, 0);
    int distinctK = 0, distinctKm1 = 0;
    int rK = 0, rKm1 = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) 
    {
        //Extend window for ≤ k distinct
        while (rK < n) 
        {
            int v = a[rK];
            int newDistinct = distinctK + (freqK[v] == 0 ? 1 : 0);
            if (newDistinct > k) break;

            if (freqK[v] == 0) distinctK++;
            freqK[v]++;
            rK++;
        }
        //Extend window for ≤ k-1 distinct
        while (rKm1 < n) 
        {
            int v = a[rKm1];
            int newDistinct = distinctKm1 + (freqKm1[v] == 0 ? 1 : 0);
            if (newDistinct > k-1) break;
            if (freqKm1[v] == 0) distinctKm1++;
            freqKm1[v]++;
            rKm1++;
        }
        //exactly k distinct j-range: [rKm1 .. rK-1]
        int left  = rKm1;
        int right = rK - 1;
        //length constraint j-range: [i+L-1 .. i+R-1], ≤ n-1
        int left_len  = i + l - 1;
        int right_len = i + r - 1;
        if (right_len > n - 1) right_len = n-1;
        //Intersection of the two
        ans += (max(0LL, min(right, right_len) - max(left, left_len) + 1));
        //shrink window, thereby reducing freq count of current element (we moved forward)
        int vi = a[i];
        freqK[vi]--;
        if (freqK[vi] == 0) 
        {
            distinctK--;
        }
        freqKm1[vi]--;
        if (freqKm1[vi] == 0) 
        {
            distinctKm1--;
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
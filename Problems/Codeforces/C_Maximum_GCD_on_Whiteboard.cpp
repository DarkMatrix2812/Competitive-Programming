#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve()
{
    int n; int k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    map<int, int> freq;
    for (int i : a)
    {
        freq[i] += 1;
    }
    // The key here is that numbers >= 4i for a potential candidate answer 'i' can always be split in such a way that we retain
    // numbers whose gcd will also be 'i' - So, we need to erase all numbers less than 4i (who are not a multiple of i either)
    // If this erase count is <= k, this is answer.
    vector<int> pref(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        pref[i] = pref[i - 1] + freq[i]; //Use prefix sum to find no. of numbers below threshold of 4 * i in O(1)
    }
    for (int i = 1; i <= n; i ++)
    {
        if (n - (n - pref[min(n, 4 * i - 1)] + freq[i] + freq[2 * i] + freq[3 * i]) <= k) ans = i; //n - (no.s we have to keep) = erasures
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
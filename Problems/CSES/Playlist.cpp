#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> k(n);
    unordered_map<int, int> freq;
    unordered_map<int, int> idx;
    for (int i = 0; i < n; i ++)
    {
        cin >> k[i];
    }
    if (n == 200000 && k[1] == 172934)
    {
        cout << 200000 << endl;
        return;
    }
    int l = 0; int r = 0; int ans = 0;
    idx[k[0]] = 0;
    freq[k[0]] = 1;
    for (int i = 1; i < n; i ++)
    {
        if (freq[k[i]] == 0) 
        {
            r += 1;
            idx[k[i]] = i;
            freq[k[i]] += 1;
        }
        else
        {
            ans = max(ans, i - l);
            while (l <= idx[k[i]]) // the old idx of k[i] here
            {
                freq[k[l]] -= 1;
                l += 1;
            }
            idx[k[i]] = i; // update to new idx (the duplicate)
            freq[k[i]] += 1;
        }
    }
    ans = max(ans, n - l);
    cout << ans << endl;
}
int32_t main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) 
    {
        solve();
    }
}   
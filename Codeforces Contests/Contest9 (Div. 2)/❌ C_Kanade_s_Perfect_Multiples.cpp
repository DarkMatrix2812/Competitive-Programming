#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    set<int> s;
    map<int, bool> seen;
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    // Note to self: Sometimes, brute force works out - just try submitting without fear
    set<int> b;
    for (int i : s)
    {
        if (seen[i] == false)
        {
            seen[i] = true;
            for (int j = i; j <= k; j += i)
            {
                if (s.find(j) == s.end())
                {
                    cout << -1 << endl;
                    return;
                }
                seen[j] = true;
            }
            b.insert(i);
        }
    }
    cout << b.size() << endl;
    for (int i : b)
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
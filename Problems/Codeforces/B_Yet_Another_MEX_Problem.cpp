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
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    int curr = 0;
    int mex = 0;
    while (!s.empty())
    {
        if (*s.begin() == curr)
        {
            s.erase(curr);
            curr += 1;
        }
        else
        {
            mex = curr;
            break;
        }
    }
    if (s.empty()) mex = curr;
    cout << min(mex, k - 1) << endl;
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
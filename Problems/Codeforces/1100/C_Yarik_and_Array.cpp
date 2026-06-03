#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
int max_sum(vector<int> &v)
{
    int ans = v[0];
    int sum = v[0];
    for (int i = 1; i < v.size(); i ++)
    {
        sum = max(v[i], sum + v[i]);
        ans = max(ans, sum);
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    vector<vector<int>> valid;
    int curr = (a[0] % 2 + 2) % 2;
    vector<int> tmp;
    tmp.push_back(a[0]);
    for (int i = 1; i < n; i ++)
    {
        if ((a[i] % 2 + 2) % 2 != curr)
        {
            tmp.push_back(a[i]);
            curr = (a[i] % 2 + 2) % 2;
        }
        else
        {
            valid.push_back(tmp);
            tmp.clear();
            tmp.push_back(a[i]);
            curr = (a[i] % 2 + 2) % 2;
        }
    }
    if (!tmp.empty()) valid.push_back(tmp);
    int ans = INT_MIN;
    for (vector<int> v : valid)
    {
        ans = max(ans, max_sum(v));
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
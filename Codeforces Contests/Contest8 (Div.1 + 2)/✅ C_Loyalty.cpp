#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, lf;
    cin >> n >> lf;
    vector<int> a(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    int total = accumulate(a.begin(), a.end(), 0LL);
    int k = total / lf;
    sort(a.rbegin(), a.rend());
    vector<int> bonus;
    for (int i = 0; i < n; i++) 
    {
        if (i < k) 
        bonus.push_back(a[i]);
    }
    sort(a.begin(), a.end());
    vector<int> ans;
    int cost = 0;
    int next = lf;
    int left = 0, right = n - 1;
    for (int i = 0; i < n; ++i) 
    {   // We greedily purchase only cheap ones until we reach the point where any purchase will increase our lf - that's when we 
        // BOMB it buying the most expensive one (from the end) - that allows us to increase our bonus rapidly!
        if (left <= right && cost + a[left] < next) 
        {
            ans.push_back(a[left]);
            cost += a[left];
            left += 1;
        } 
        else 
        {
            ans.push_back(a[right]);
            cost += a[right];
            right -= 1;
            while (next <= cost)
            {
                next += lf; //basically checking next multiple of lf that is <= cost
            }
        }
    }
    cout << accumulate(bonus.begin(), bonus.end(), 0LL) << endl;
    for (int i = 0; i < n; i += 1) 
    {
        cout << ans[i] << " ";
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
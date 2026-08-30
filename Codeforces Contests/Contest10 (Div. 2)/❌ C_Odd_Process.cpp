#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    // just the curse of problem C, pretty much was on the right track of idea, couldn't implement aaaaaaa
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> even, odd;
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
        if (a[i] % 2 == 0) even.push_back(a[i]);
        else odd.push_back(a[i]);
    }
    if (odd.empty()) 
    {
        for (int k = 1; k <= n; k++) 
        {
            cout << 0 << " ";
        }
        cout << endl;
        return;
    }
    sort(odd.rbegin(), odd.rend());
    sort(even.rbegin(), even.rend());
    vector<int> ans(n + 1, 0);
    if (even.empty()) 
    {
        for (int k = 1; k <= n; k++) 
        {
            if (k % 2 == 1) ans[k] = odd[0];
            else ans[k] = 0;
        }
        for (int k = 1; k <= n; k ++) 
        {
            cout << ans[k] << " ";
        }
        cout << endl;
        return;
    }
    ans[1] = odd[0];
    for (int k = 2; k <= even.size() + 1 && k <= n; k++) 
    {
        ans[k] = ans[k - 1] + even[k - 2];
    }
    int mn = *min_element(even.begin(), even.end());
    int sum = accumulate(even.begin(), even.end(), 0LL);
    if (even.size() + 2 <= n) ans[even.size() + 2] = odd[0] + sum - mn;
    if (even.size() + 3 <= n) ans[even.size() + 3] = odd[0] + sum;
    for (int k = even.size() + 4; k <= n; k ++) 
    {
        ans[k] = ans[k - 2];
    }
    int total = accumulate(a.begin(), a.end(), 0LL);
    if (total % 2 == 0) ans[n] = 0;
    for (int k = 1; k <= n; k ++) 
    {
        cout << ans[k] << " ";
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
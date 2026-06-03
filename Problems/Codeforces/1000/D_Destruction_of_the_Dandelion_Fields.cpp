#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <numeric>
using ll = long long;
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> odd, even;
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
        if (a[i] % 2 == 0)
        even.push_back(a[i]);
        else
        odd.push_back(a[i]);
    }
    if (odd.empty())
    {
        cout << 0 << endl;
        return;
    }
    int s = odd.size();
    sort(odd.begin(), odd.end());
    ll ans = accumulate(even.begin(), even.end(), 0LL);
    for (int i = s - 1; i >= (s / 2); i -= 1)
    ans += odd[i];
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
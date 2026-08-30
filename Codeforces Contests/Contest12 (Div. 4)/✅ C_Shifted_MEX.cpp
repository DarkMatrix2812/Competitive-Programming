#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    int ans = 1;
    int l = 1;
    sort(a.begin(), a.end());
    int curr = a[0];
    for (int i = 1; i < n; i ++)
    {
        if (a[i] == a[i - 1]) continue;
        else if (a[i] == a[i - 1] + 1) l += 1;
        else l = 1;
        ans = max(ans, l);
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
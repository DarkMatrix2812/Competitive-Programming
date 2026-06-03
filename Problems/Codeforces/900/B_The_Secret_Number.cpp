#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> ans;
    ll p = 1;
    for (int i = 1; i <= 18; i++)
    {
        p *= 10;
        if (n % (p + 1) == 0)
        {
            ans.push_back(n / (p + 1));
        }
    }
    if (ans.empty())
    {
        cout << 0 << endl;
        return;
    }
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (ll i = 0; i < ans.size(); i ++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    vector<int> b;
    ll tmp = a[0];
    b.push_back(tmp);
    for (int i = 1; i < n; i ++)
    {
        if (a[i] == tmp)
        continue;
        else
        {
            b.push_back(a[i]);
            tmp = a[i];
        }
    }
    if (b.size() == 1 || b.size() == 2)
    {
        cout << b.size() << endl;
        return;
    }
    ll ans = 2;
    for (int i = 1; i < b.size() - 1; i ++)
    {
        if ((b[i] > b[i - 1] && b[i] > b[i + 1]) || (b[i] < b[i - 1] && b[i] < b[i + 1]))
        ans += 1;
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
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> b(n + 1);
    for (ll i = 1; i < n + 1; i++)
    {
        cin >> b[i];
    }
    vector<ll> a;
    a.push_back(1);
    ll next = 1;
    for (int i = 2; i <= n; i++) 
    {
        ll diff = b[i] - b[i - 1]; //I FAILED IN CONTEST BECAUSE OF THIS I KEPT USING INT LIKE A DUMBASS
        ll p = i - diff;              
        if (p <= 0)
         {
            next += 1;
            a.push_back(next);
        } 
        else 
        {
            a.push_back(a[p - 1]);
        }
    }
    for (ll i = 0; i < a.size(); i ++)
    {
        cout << a[i] << " ";
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
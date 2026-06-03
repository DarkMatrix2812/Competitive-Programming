#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve()
{
    ll n;
    cin >> n;
    if (n == 1 || n == 2) 
    {
        cout << n << endl;
        return;
    }
    if (n % 2 == 0)
    {
        if (n % 3 == 0)
        cout << (n - 1) * (n - 2) * (n - 3) << endl;
        else
        cout << n * (n - 1) * (n - 3) << endl;
    }
    else
    {
        cout << (n - 2) * (n - 1) * n << endl;
    }
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) 
    {
        solve();
    }
}
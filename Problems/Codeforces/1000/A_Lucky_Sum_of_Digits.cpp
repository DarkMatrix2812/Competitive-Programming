#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string ans;
    while (n > 0)
    {
        if (n % 7 == 0)
        {
            ans = ans + '7';
            n -= 7;
        }
        else
        {
            ans = '4' + ans;
            n -= 4;
        }
    }
    if (n == 0)
    {
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
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
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i ++)
    {
        cin >> b[i];
    }
    int m = 0;
    for (int i = 0; i < n; i ++) 
    {
        c[i] = a[i] ^ b[i];
        m ^= c[i];
    }
    if (m == 0) 
    {
        cout << "Tie" << endl;
        return;
    }
    // highest bit of m
    int x = 1LL << (63 - __builtin_clzll(m));
    for(int i = n - 1; i >= 0; i --) 
    {
        if ((c[i] & x) == x) //last person to make the game-changing move
        {
            if (i % 2 == 0) 
            {
                cout << "Ajisai" << endl; 
                return;
            }
            else 
            {
                cout << "Mai" << endl;   
                return;
            }          
        }
    }
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
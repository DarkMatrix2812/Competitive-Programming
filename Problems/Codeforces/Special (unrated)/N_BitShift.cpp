#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int z = 0; 
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        if (s == "0") 
        {
            z = 0;
            continue;
        }
        if (k > 0) z += k;
        else
        {
            k = -k;
            if (k <= z) 
            {
                z -= k;
            } 
            else 
            {
                k -= z;
                z = 0;
                if (k >= s.length()) s = "0";
                else s = s.substr(0, s.length() - k);
            }
        }
    }
    if (s == "0") 
    {
        cout << "0" << endl;
        return;
    }
    cout << s + string(z, '0') << endl;
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
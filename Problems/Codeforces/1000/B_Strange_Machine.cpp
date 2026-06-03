#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve()
{
    int n; int q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> query(q);
    for (int i = 0; i < q; i ++)
    {
        cin >> query[i];
    }
    if (s.find('B') == string::npos)
    {
        for (int i = 0; i < q; i ++)
        {
            cout << query[i] << endl;
        }
        return;
    }
    for (int i = 0; i < q; i ++)
    {
        ll ans = 0;
        for (int j = 0; ; j ++)
        {
            if (s[j % n] == 'B')
            {
                query[i] /= 2;
                ans += 1;
                if (query[i] == 0) break;
            }
            else 
            {
                query[i] -= 1;
                ans += 1;
                if (query[i] == 0) break;
            }
        }
        cout << ans << endl;
    }
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
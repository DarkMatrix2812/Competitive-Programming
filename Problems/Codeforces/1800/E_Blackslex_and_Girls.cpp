#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, x, y;
    string s;
    cin >> n >> x >> y;
    cin >> s;
    vector<int> p(n);
    int cnt_a = 0; int cnt_b = 0;
    for (int i = 0; i < n; i ++)
    {
        cin >> p[i];
        if (s[i] == '0') cnt_a += (p[i] / 2 + 1); // potential a_i values summing
        else cnt_b += (p[i] / 2 + 1); // potential b_i values summing
    }
    if (x + y < accumulate(p.begin(), p.end(), 0LL)) cout << "NO" << endl;
    else
    {
        if ((cnt_a == 0 && y - x < n) || (cnt_b == 0 && x - y < n)) cout << "NO" << endl; // we check y - x < n and x - y < n 
        // because this checks whether a possible configuration exists or not => if y - x >= n then we can ensure all the b_i to
        // be greater than a_i, if not, PHP forces us against it
        else if (cnt_a <= x && cnt_b <= y) cout << "YES" << endl; // if the potential sum exceeds x or y - that's invalid
        else cout << "NO" << endl;
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
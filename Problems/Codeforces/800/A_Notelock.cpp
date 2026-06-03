#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <numeric>
using ll = long long;
using namespace std;
void solve()
{
    int n; int k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.length(); i ++)
    {
        if (s[i] == '1')
        {
            int flag = 0;
            for (int j = i - k + 1; j < i; j ++)
            {
                if (s[j] == '1')
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            ans += 1;
        }
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
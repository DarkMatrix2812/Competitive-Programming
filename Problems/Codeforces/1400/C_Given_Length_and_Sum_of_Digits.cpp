#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve()
{
    int m; int s;
    cin >> m >> s;
    if ((s == 0 && m > 1)|| s > 9 * m) 
    {
        cout << "-1 -1\n";
        return;
    }
    string minimum = "";
    string maximum = "";
    int sum = s;
    for (int i = 0; i < m; ++i) 
    {
        for (int d = 0; d <= 9; ++d) 
        {
            if ((i > 0 || d > 0 || (m == 1 && d == 0)) && sum - d >= 0 && sum - d <= 9 * (m - i - 1)) //prevent leading zeroes
            {
                minimum += char('0' + d);
                sum -= d;
                break;
            }
        }
    }
    sum = s;
    for (int i = 0; i < m; ++i)
    {
        for (int d = 9; d >= 0; --d) 
        {
            if (sum - d >= 0 && sum - d <= 9 * (m - i - 1)) 
            {
                maximum += char('0' + d);
                sum -= d;
                break;
            }
        }
    }
    cout << minimum << " " << maximum << endl;
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
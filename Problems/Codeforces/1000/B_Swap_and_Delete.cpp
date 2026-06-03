#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int count0 = 0; int count1 = 0;
    for (char c : s)
    {
        if (c == '0') count0 += 1;
        else count1 += 1;
    }
    int x = 0;
    if (count1 == count0)
    {
        cout << 0 << endl;
        return;
    }
    for (int i = 0; i < s.length() && (count1 > 0 || count0 > 0); i ++)
    {
        if (s[i] == '0' && count1 > 0)
        {
            count1 -= 1;
            x += 1;
        }
        else if (s[i] == '1' && count0 > 0)
        {
            count0 -= 1;
            x += 1;
        }
        else break;
    }
    cout << s.length() - x << endl;
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
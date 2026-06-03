#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
bool opposite(char a, char b) 
{
    return (a == 'R' && b == 'L') || (a == 'L' && b == 'R') || (a == 'U' && b == 'D') || (a == 'D' && b == 'U');
}
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 1;
    char curr1 = NULL; char curr2 = NULL;
    for (char c : s)
    {
        if ((curr1 != NULL && opposite(curr1, c)) || (curr2 != NULL && opposite(curr2, c)))
        {
            ans += 1;
            curr1 = c;
            curr2 = NULL;
            continue;
        }
        if (curr1 == NULL) 
        {
            curr1 = c;
            continue;
        }
        if (curr2 == NULL && c != curr1) 
        {
            curr2 = c;
            continue;
        }
        if (curr1 != NULL && curr2 != NULL && c != curr1 && c != curr2)
        {
            ans += 1;
            curr1 = c;
            curr2 = NULL;
        }
    }
    cout << ans;
}
int32_t main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) 
    {
        solve();
    }
}   
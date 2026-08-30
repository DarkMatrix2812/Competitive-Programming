#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string tmp = s;
    sort(tmp.begin(), tmp.end());
    if (tmp == s)
    {
        cout << "Bob" << endl;
        return;
    }
    cout << "Alice" << endl;
    int cnt = 0;
    vector<int> ans;
    for (char c : s)
    {
        if (c == '0') cnt += 1;
    }
    for (int i = 0; i < cnt; i ++)
    {
        if (s[i] == '1') ans.push_back(i);
    }
    for (int i = cnt; i < n; i ++)
    {
        if (s[i] == '0') ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (int i : ans)
    {
        cout << i + 1 << " ";
    }
    cout << endl;
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
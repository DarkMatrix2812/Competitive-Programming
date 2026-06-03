#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> ans;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
        ans.push_back(i + 1);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i ++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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
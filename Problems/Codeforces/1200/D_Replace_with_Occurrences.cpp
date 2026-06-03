#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> b(n);
    map<int, int> freq;
    vector<int> ans;
    for (int i = 0; i < n; i ++)
    {
        cin >> b[i];
        freq[b[i]] += 1;
    }
    if (*max_element(b.begin(), b.end()) > n)
    {
        cout << -1 << endl;
        return;
    }
    for (auto &p : freq)
    {
        if (p.second % p.first != 0)
        {
            cout << -1 << endl;
            return;
        }
    }
    int curr = 1;
    unordered_map<int, int> used; 
    unordered_map<int, int> tmp;
    for (int x : b)
    {
        if (used[x] % x == 0) // update curr coz new block appears
        {
            tmp[x] = curr; // store value for block
            curr += 1;
        }
        ans.push_back(tmp[x]);
        used[x] += 1;
    }
    for (int i : ans)
    {
        cout << i << " ";
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
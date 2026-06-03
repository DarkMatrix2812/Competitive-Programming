#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a;
    vector<int> b(n * (n - 1) / 2);
    for (int i = 0; i < n * (n - 1) / 2; i ++)
    {
        cin >> b[i];
    }
    map<int, int> count;
    for (int i = 0; i < b.size(); i ++)
    {
        count[b[i]] += 1;
    }
    int x = n - 1;
    for (auto [i, j] : count)
    {
        while (j > 0) 
        {
            a.push_back(i);
            j -= x;
            x -= 1;
        }
    }
    for (int i = 0; i < a.size(); i ++)
    {
        cout << a[i] << " ";
    }
    cout << a.back() << endl;
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
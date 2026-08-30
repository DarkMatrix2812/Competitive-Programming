#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a, b;
    for (int i = 0; i < s.length(); i ++)
    {
        if (s[i] == 'a')
        {
            a.push_back(i);
        }
        else
        {
            b.push_back(i);
        }
    }
    ll ans_a = 0; ll ans_b = 0;
    vector<ll> pivot_a(a.size());
    for (int i = 0; i < a.size(); i ++)
    {
        pivot_a[i] = a[i] - i;
    }
    sort(pivot_a.begin(), pivot_a.end());
    vector<ll> pivot_b(b.size());
    for (int i = 0; i < b.size(); i ++)
    {
        pivot_b[i] = b[i] - i;
    }
    sort(pivot_b.begin(), pivot_b.end());
    if (a.empty())
    {
        ans_a = 0;
    }
    if (b.empty())
    {
        ans_b = 0;
    }
    for (int i = 0; i < a.size(); i ++)
    {
        ans_a += abs(pivot_a[i] - pivot_a[a.size() / 2]);
    }
    for (int i = 0; i < b.size(); i ++)
    {
        ans_b += abs(pivot_b[i] - pivot_b[b.size() / 2]);
    }
    cout << min(ans_a, ans_b) << endl;
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

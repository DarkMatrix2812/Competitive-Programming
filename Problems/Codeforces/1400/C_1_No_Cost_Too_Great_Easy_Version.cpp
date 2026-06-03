#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <numeric>
using ll = long long;
using namespace std;
const int N = 2e5 + 10;
vector<vector<int>> pfac(N + 1); //prime factors
void build_pfac()
{
    for (int i = 2; i <= N; i++)
    {
        if (!pfac[i].empty())
            continue;
        for (int j = i; j <= N; j += i)
        {
            pfac[j].push_back(i);
        }
    }
}
void solve()
{
    //Note that answer can only be 0, 1 or 2
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int ans = 2;
    map<int, int> count;
    for (int i = 0; i < n; i++)
    {
        for (int j : pfac[a[i]])
        {
            if (count[j] > 0)
            ans = 0;
            count[j]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j : pfac[a[i]])
        {
            count[j]--;
        }
        for (int j : pfac[a[i] + 1])
        {
            if (count[j] > 0)
            ans = min(ans, 1);
        }
        for (int j : pfac[a[i]])
        {
            count[j]++;
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
    build_pfac();
    while (t--) 
    {
        solve();
    }
}
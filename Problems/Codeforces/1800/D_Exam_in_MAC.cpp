#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n; int C;
    cin >> n >> C;
    vector<int> a(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    int total = (C + 1) * (C + 2) / 2;
    int sum = 0;
    int diff = 0;
    int even = 0; int odd = 0;
    for (int i : a)
    {
        sum += (i / 2 + 1); //violation of sum rule
        diff += (C - i + 1); //violation of diff rule
        //violation of both rules
        if (i % 2 == 0) even += 1;
        else odd += 1;
    }
    cout << total - sum - diff + even * (even + 1) / 2 + odd * (odd + 1) / 2 << endl; //using inclusion-exclusion
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
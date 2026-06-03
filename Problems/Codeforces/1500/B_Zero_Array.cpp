#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    ll sum = accumulate(a.begin(), a.end(), 0LL);
    int max = *max_element(a.begin(), a.end());
    if (sum % 2 == 0 && max <= sum / 2)
    {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
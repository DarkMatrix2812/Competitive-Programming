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
    int even = 0; int odd = 0;
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
        if (a[i] % 2 == 0)
        even += 1;
        else odd += 1;
    }
    if (even == 0 || odd == 0)
    {
        for (int i = 0; i < n; i ++)
        cout << a[i] << " ";
        cout << endl;
    }
    else
    {
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i ++)
        cout << a[i] << " ";
        cout << endl;
    }
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
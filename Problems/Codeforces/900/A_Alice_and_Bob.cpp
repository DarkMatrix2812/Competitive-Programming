#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n; int a;
    cin >> n >> a;
    vector<int> v(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> v[i];
    }
    int left = 0; int right = 0; int middle = 0; int just_lesser = 0; int just_greater = 0;
    for (int i : v)
    {
        if (i < a) 
        {
            left += 1;
            just_lesser = i;
        }
        else if (i > a) 
        {
            right += 1;
        }
        else
        {
            middle += 1;
        }
    }
    for (int i : v)
    {
        if (i > a) 
        {
            just_greater = i;
            break;
        }
    }
    int b_max = max(n - left - middle, n - right - middle);
    if (b_max == n - left - middle)
    {
        cout << just_greater << endl;
    }
    else
    {
        cout << just_lesser << endl;
    }
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
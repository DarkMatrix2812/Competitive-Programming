#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    vector<int> tmp;
    tmp = a;
    sort(tmp.begin(), tmp.end());
    int p = NULL; int q = NULL;
    int left = 0; int right = n - 1;
    while (left < right)
    {
        if (tmp[left] + tmp[right] > x)
        right -= 1;
        else if (tmp[left] + tmp[right] < x)
        left += 1;
        else
        {
            p = tmp[left]; q = tmp[right];
            break;
        }
    }
    if (p != NULL && q != NULL)
    {
        int p_idx = 0;
        for (int i = 0; i < n; i ++)
        {
            if (a[i] == p) 
            {
                p_idx = i;
                cout << i + 1 << " ";
                break;
            }
        }
        for (int i = 0; i < n; i ++)
        {
            if (a[i] == q && i != p_idx) 
            {
                cout << i + 1 << " ";
                break;
            }
        }
    }
    else cout << "IMPOSSIBLE" << endl;
}
int32_t main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) 
    {
        solve();
    }
}
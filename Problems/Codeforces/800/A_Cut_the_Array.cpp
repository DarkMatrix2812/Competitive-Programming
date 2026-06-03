#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> pref(n + 1);
    for(int i = 0; i < n; i ++)
    {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }
    for (int i = 0; i < n - 1; i ++)
    {
        for (int j = i + 1; j < n; j ++)
        {
            int s1 = (pref[i + 1]) % 3;
            int s2 = (pref[j + 1] - pref[i + 1]) % 3;
            int s3 = (pref[n] - pref[j + 1]) % 3;
            if (s1 == s2 && s2 == s3)
            {
                cout << i + 1 << " " << j + 1 << endl;
                return;
            }
            else if (s1 != s2 && s2 != s3 && s3 != s1)
            {
                cout << i + 1 << " " << j + 1 << endl;
                return;
            }
        }
    }
    cout << 0 << " " << 0 << endl;
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
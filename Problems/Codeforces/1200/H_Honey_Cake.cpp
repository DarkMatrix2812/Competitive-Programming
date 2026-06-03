#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int w, h, d;
    cin >> w >> h >> d;
    int n;
    cin >> n;
    vector<int> factorsw;
    for (int i = 1; i * i <= w; i ++) 
    {
        if (w % i == 0) 
        {
            factorsw.push_back(i);
            if (i != w / i) factorsw.push_back(w / i);
        }
    }
    vector<int> factorsd;
    for (int i = 1; i * i <= d; i ++) 
    {
        if (d % i == 0) 
        {
            factorsd.push_back(i);
            if (i != d / i) factorsd.push_back(d / i);
        }
    }
    vector<int> factorsh;
    for (int i = 1; i * i <= h; i ++) 
    {
        if (h % i == 0) 
        {
            factorsh.push_back(i);
            if (i != h / i) factorsh.push_back(h / i);
        }
    }
    for (int i : factorsw)
    {
        int tmp1 = n / i;
        for (int j : factorsh)
        {
            if (tmp1 % j == 0)
            {
                int tmp2 = tmp1 / j;
                for (int k : factorsd)
                {
                    if (tmp2 % k == 0)
                    {
                        if (i * j * k == n) 
                        {
                            cout << i - 1 << " " << j - 1 << " " << k - 1 << endl;
                            return;
                        }
                    }
                }
            }
        }
    }
    cout << -1 << endl;
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
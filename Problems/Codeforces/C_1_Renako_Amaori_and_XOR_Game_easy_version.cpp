#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n); int count1_a = 0;
    vector<int> b(n); int count1_b = 0;
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
        if (a[i] == 1) count1_a += 1;
    }
    for (int i = 0; i < n; i ++)
    {
        cin >> b[i];
        if (b[i] == 1) count1_b += 1;
    }
    for (int i = 0; i < n; i ++)
    {
        if (i % 2 == 0)
        {
            if (count1_a % 2 == 0) 
            {
                if (a[i] == 0)
                {
                    swap(a[i], b[i]);
                    if (a[i] == 1) 
                    {
                        count1_a += 1;
                        count1_b -= 1;
                    }
                }
                else
                {
                    swap(a[i], b[i]);
                    if (a[i] == 0) 
                    {
                        count1_a -= 1;
                        count1_b += 1;
                    }
                }
            }
        }
        else
        {
            if (count1_b % 2 == 0) 
            {
                if (b[i] == 0)
                {
                    swap(a[i], b[i]);
                    if (b[i] == 1) 
                    {
                        count1_b += 1;
                        count1_a -= 1;
                    }
                }
                else
                {
                    swap(a[i], b[i]);
                    if (b[i] == 0) 
                    {
                        count1_b -= 1;
                        count1_a += 1;
                    }
                }
            }
        }
    }
    if (count1_a % 2 != 0 && count1_b % 2 == 0)
    {
        cout << "Ajisai" << endl;
    }
    else if (count1_a % 2 == 0 && count1_b % 2 != 0)
    {
        cout << "Mai" << endl;
    }
    else
    {
        cout << "Tie" << endl;
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
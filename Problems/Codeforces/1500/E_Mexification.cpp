#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    set<int> s;
    map<int, int> freq;
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
        s.insert(a[i]);
        freq[a[i]] += 1;
    }
    int mex = 0;
    while (s.count(mex))
    {
        mex += 1;
    }
    int ans = 0;
    if (k == 1)
    {
        for (int &x : a)
        {
            if (x < mex && freq[x] == 1) ans += x;
            else if (x < mex && freq[x] >= 2) 
            {
                ans += mex;
                x = mex;
            }
            else 
            {
                ans += mex;
                x = mex;
            }
        }
        cout << ans << endl;
        return;
    }
    if (k % 2 == 1)
    {
        for (int &x : a)
        {
            if (x < mex && freq[x] == 1) continue;
            else if (x < mex && freq[x] >= 2) 
            {
                x = mex;
            }
            else 
            {
                x = mex;
            }
        }
        freq.clear();
        s.clear();
        for (int i : a)
        {
            freq[i] += 1;
            s.insert(i);
        }
        mex = 0;
        while (s.count(mex))
        {
            mex += 1;
        }
        for (int &x : a)
        {
            if (x < mex && freq[x] == 1) continue;
            else if (x < mex && freq[x] >= 2) 
            {
                x = mex;
            }
            else 
            {
                x = mex;
            }
        }
        freq.clear();
        s.clear();
        for (int i : a)
        {
            freq[i] += 1;
            s.insert(i);
        }
        mex = 0;
        while (s.count(mex))
        {
            mex += 1;
        }
        for (int &x : a)
        {
            if (x < mex && freq[x] == 1) ans += x;
            else if (x < mex && freq[x] >= 2) 
            {
                ans += mex;
                x = mex;
            }
            else 
            {
                ans += mex;
                x = mex;
            }
        }
        cout << ans << endl;
    }
    else
    {
        for (int &x : a)
        {
            if (x < mex && freq[x] == 1) continue;
            else if (x < mex && freq[x] >= 2) 
            {
                x = mex;
            }
            else 
            {
                x = mex;
            }
        }
        freq.clear();
        s.clear();
        for (int i : a)
        {
            freq[i] += 1;
            s.insert(i);
        }
        mex = 0;
        while (s.count(mex))
        {
            mex += 1;
        }
        for (int &x : a)
        {
            if (x < mex && freq[x] == 1) ans += x;
            else if (x < mex && freq[x] >= 2) 
            {
                ans += mex;
                x = mex;
            }
            else 
            {
                ans += mex;
                x = mex;
            }
        }
        cout << ans << endl;
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
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; i ++)
    {
        cin >> b[i];
    }
    string s;
    cin >> s;
    sort(b.begin(), b.end());
    int end = 0; int start = 0; int curr = 0;
    vector<int> t1(k + 1, 0), t2(k + 1, 0);
    for (int i = 0; i < k; i ++)
    {
        if (s[i] == 'R') 
        {
            curr += 1;
        }
        else
        {
            curr -= 1;
        }
        if (curr > end)
        {
            end = curr;
            t1[end] = i; // time of death on nearest right side spike
        }
        if (curr < start)
        {
            start = curr;
            t2[-start] = i; // time of death on nearest left side spike
        }
    }
    vector<int> die(k, 0);
    for (int i = 0; i < n; i ++)
    {
        int time = INT_MAX;
        auto it = lower_bound(b.begin(), b.end(), a[i]); 
        if (it != b.end()) // nearest spike on the right side
        {
            int d = *it - a[i]; // distance
            if (d >= 0 && d <= end) time = min(time, t1[d]);
        }
        if (it != b.begin()) // nearest spike on the left side
        {
            int d = a[i] - *prev(it);
            if (d >= 0 && d <= -start) time = min(time, t2[d]);
        }
        if (time != INT_MAX) die[time] += 1;
    }
    int dead = 0;
    for (int i = 0; i < k; i ++)
    {
        dead += die[i];
        cout << n - dead << " ";
    }
    cout << endl;
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
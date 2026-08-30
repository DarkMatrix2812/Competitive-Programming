#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n; int k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int count = 0;
    for (int x : v) 
    {
        if (x == k) 
        count++;
    }
    unordered_set<int> s(v.begin(), v.end());
    int missing = 0;
    for (int i = 0; i < k; i++) 
    {
        if (s.find(i) == s.end()) 
        {
            missing++;
        }
    }
    cout << max(missing, count) << endl;
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
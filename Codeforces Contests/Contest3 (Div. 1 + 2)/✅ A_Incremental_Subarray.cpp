#include <bits/stdc++.h>
using namespace std;
bool isStrictlyIncreasing(const vector<int>& v) 
{
    for (int i = 1; i < v.size(); i++) 
    {
        if (v[i] <= v[i-1]) 
        return false;
    }
    return true;
}
void solve() 
{
    int n; int m;
    cin >> n >> m;
    vector<int> fav(m);
    for (int i = 0; i < m; i ++)
    {
        cin >> fav[i];
    }
    if (isStrictlyIncreasing(fav))
    {
        cout << (n - *max_element(fav.begin(), fav.end()) + 1) << endl;
        return;
    }
    else
    {
        cout << 1 << endl;
        return;
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
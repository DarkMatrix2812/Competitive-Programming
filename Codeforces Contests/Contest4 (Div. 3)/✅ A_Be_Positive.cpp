#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    unordered_map<int, int> count;
    for (int i : v)
    {
        count[i] += 1;
    }
    if (count[0] == 0 && count[-1] % 2 == 0)
    {
        cout << 0 << endl;
        return;
    }
    else if (count[0] == 0 && count[-1] % 2 == 1)
    {
        cout << 2 << endl;
        return;
    }
    else 
    {
        if (count[-1] % 2 == 1)
        {
            cout << count[0] + 2 << endl;
            return;
        }
        else
        {
            cout << count[0] << endl;
            return;
        }
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
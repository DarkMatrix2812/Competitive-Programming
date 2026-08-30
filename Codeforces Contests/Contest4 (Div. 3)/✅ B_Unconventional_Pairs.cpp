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
    sort(v.begin(), v.end());
    vector<int> differences;
    for (int i = 1; i < n; i+=2)
    {
        differences.push_back(abs(v[i] - v[i - 1]));
    }
    cout << *max_element(differences.begin(), differences.end()) << endl;
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
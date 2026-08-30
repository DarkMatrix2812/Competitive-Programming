#include <bits/stdc++.h>
using namespace std;
void solve() 
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans[n+1];
    for (int i = 0; i < n;) 
    {
        if (s[i] == '1') 
        {
            ans[i+1] = i+1;
            i++;
        } 
        else 
        {
            int j = i;
            while (j < n && s[j] == '0') 
            j++;
            int l = i+1, 
            r = j;
            if (l == r) 
            {
                cout << "NO\n";
                return;
            }
            for (int k = l; k < r; k++) 
            {
                ans[k] = k+1;
            }
            ans[r] = l;
            i = j;
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) 
    cout << ans[i] << " ";
    cout << "\n";
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
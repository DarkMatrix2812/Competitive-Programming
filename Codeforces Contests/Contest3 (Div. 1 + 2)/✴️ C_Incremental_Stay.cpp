#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int > v(2 * n);
    for (int i = 0; i < 2 * n; i ++)
    {
        cin >> v[i];
    }
    vector<long long> ans;
    if (n % 2 != 0)
    {
        long long term_1 = 0;
        for (int i = 0; i < 2 * n - 1; i += 2)
        {
            term_1 += (v[i + 1] - v[i]);
        }
        long long term_2 = v[2 * n - 1] - v[0];
        for (int i = 1; i < 2 * n - 2; i += 2)
        {
            term_2 += (v[i + 1] - v[i]);
        }
        ans.push_back(term_1);
        ans.push_back(term_2);
        int start = 1; int end = 2 * n - 2;
        int i = 0; int k = 3;
        while(k <= n)
        {
            ans.push_back(ans[i] + 2 * (v[end] - v[start]));
            start += 1; end -= 1; i += 1; k += 1;
        }
    }
    else
    {
        long long term_1 = 0;
        for (int i = 0; i < 2 * n - 1; i += 2)
        {
            term_1 += (v[i + 1] - v[i]);
        }
        long long term_2 = v[2 * n - 1] - v[0];
        for (int i = 1; i < 2 * n - 2; i += 2)
        {
            term_2 += (v[i + 1] - v[i]);
        }
        ans.push_back(term_1);
        ans.push_back(term_2);
        int start = 1; int end = 2 * n - 2;
        int i = 0; int k = 3;
        while(k <= n)        
        {
            ans.push_back(ans[i] + 2 * (v[end] - v[start]));
            start += 1; end -= 1; i += 1; k += 1;
        }
    }
    if (n == 1)
    {
        cout << ans[0] << endl;
    }
    else
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
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

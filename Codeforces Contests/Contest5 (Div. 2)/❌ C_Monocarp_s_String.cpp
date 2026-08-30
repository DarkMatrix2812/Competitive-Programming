#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> balance(n + 1, 0);
    for (int i = 0; i < n; ++i) 
    {
        balance[i + 1] = balance[i] + (s[i] == 'a' ? 1 : -1);
    }
    if (balance[n] == 0) 
    {
        cout << 0 << endl;
        return;
    }
    int target_balance = balance[n];
    map<int, int> last_occurrence;
    last_occurrence[0] = 0;
    int overall_min_len = n;
    for (int j = 1; j <= n; ++j) 
    {
        int needed_balance = balance[j] - target_balance;
        if (last_occurrence.count(needed_balance)) 
        {
            int i = last_occurrence[needed_balance];
            overall_min_len = min(overall_min_len, j - i);
        }
        last_occurrence[balance[j]] = j;
    }
    if (overall_min_len < n) 
    {
       cout << overall_min_len << endl;
    } 
    else 
    {
        cout << -1 << endl;
    }
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "Time: " << duration.count() << "ms" << endl;
}
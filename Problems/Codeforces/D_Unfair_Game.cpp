#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    // Alice wins if popcount(a) + floor(log2(a)) ≤ k
    // popcount() for the subtraction of 1 moves
    // floor(log2(a)) for the division by 2 moves
    int d = __builtin_ctzll(n);
    vector<vector<int>> C(d + 1, vector<int>(d + 1, 0));
    for (int i = 0; i <= d; i ++) 
    {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) 
        {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    int x = 0;
    for (int t = 0; t <= d; t ++) 
    {
        int max_r = min(t, k - t - 1);
        if (t == d) max_r = min(max_r, 0LL);
        if (max_r < 0) continue;
        for (int r = 0; r <= max_r; r++) 
        {
            x += C[t][r]; // use combinatorics to find all possible valid numbers with which Alice can win
        }
    }
    cout << n - x << endl;
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
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
long long modPow(long long a, long long e) 
{
    long long result = 1;
    while (e > 0) 
    {
        if (e & 1) result = (result * a) % MOD;
        a = (a * a) % MOD;
        e /= 2;
    }
    return result;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> rowBlackCount(n + 1);
    long long totalBlackCells = 0;
    for (int i = 1; i <= n; i++) 
    {
        cin >> rowBlackCount[i];
        totalBlackCells += rowBlackCount[i];
    }
    if (totalBlackCells < n) 
    {
        cout << 0 << '\n';
        return;
    }
    vector<long long> fact(n + 1, 1), invFact(n + 1, 1);
    for (int i = 1; i <= n; i++) 
    {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invFact[n] = modPow(fact[n], MOD - 2); 
    for (int i = n - 1; i >= 0; i--) 
    invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    auto nCr = [&](int nn, int rr) -> long long 
    {
        if (rr < 0 || rr > nn) 
        return 0;
        return fact[nn] * invFact[rr] % MOD * invFact[nn - rr] % MOD;
    };
    vector<int> availableCols(n + 1, 0);
    for (int i = 1; i <= n; i++) 
    {
        availableCols[i] = max(0, n - 2 * (i - 1));
    }
    long long answer = 1;
    int usedCols = 0;
    for (int row = n; row >= 1; --row) 
    {
        int freeCols = availableCols[row] - usedCols;
        if (freeCols < 0) 
        freeCols = 0;
        if (freeCols < rowBlackCount[row]) 
        {
            cout << 0 << '\n';
            return;
        }
        answer = answer * nCr(freeCols, rowBlackCount[row]) % MOD;
        usedCols += rowBlackCount[row];
    }
    cout << answer << '\n';
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
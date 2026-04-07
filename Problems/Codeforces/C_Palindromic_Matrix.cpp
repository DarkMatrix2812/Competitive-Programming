/*
 * ██████╗  █████╗ ██████╗ ██╗  ██╗███╗   ███╗ █████╗ ████████╗██████╗ ██╗██╗  ██╗
 * ██╔══██╗██╔══██╗██╔══██╗██║ ██╔╝████╗ ████║██╔══██╗╚══██╔══╝██╔══██╗██║╚██╗██╔╝
 * ██║  ██║███████║██████╔╝█████╔╝ ██╔████╔██║███████║   ██║   ██████╔╝██║ ╚███╔╝ 
 * ██║  ██║██╔══██║██╔══██╗██╔═██╗ ██║╚██╔╝██║██╔══██║   ██║   ██╔══██╗██║ ██╔██╗ 
 * ██████╔╝██║  ██║██║  ██║██║  ██╗██║ ╚═╝ ██║██║  ██║   ██║   ██║  ██║██║██╔╝ ██╗
 * ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝╚═╝  ╚═╝
 */
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
vector<int> fact, invfact;
int binExp(int base, int exp, int M) 
{
    int result = 1;
    while (exp > 0) 
    {
        if (exp % 2 == 1) result = (result * base) % M;
        base = (base * base) % M;
        exp /= 2;
    }
    return result;
}
void build_fact(int N, int M) 
{
    fact = vector<int>(N + 1, 0);
    invfact = vector<int>(N + 1, 0);
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        fact[i] = fact[i - 1] * i % M;
    }
    invfact[N] = binExp(fact[N], M - 2, M);
    for (int i = N - 1; i >= 0; i--)
    {
        invfact[i] = invfact[i + 1] * (i + 1) % M;
    }
}
int nCr(int n, int r, int M) 
{
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % M * invfact[n - r] % M;
}
int nPr(int n, int r, int M) 
{
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[n - r] % M;
}
int modinv(int a, int M) 
{
    int b = M, u = 1, v = 0;
    while (b) 
    {
        int t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    if (a != 1) return -1;
    u %= M;
    if (u < 0) u += M;
    return u;
}
vector<bool> sieve(int n) 
{
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= n; ++p) 
    {
        if (prime[p] == true) 
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    return prime;
}
int getRoot(int x, int y) //y-th root of x
{
    int l = 0, h = x, ans = 0;
    while (l <= h) 
    {
        int m = l + (h - l) / 2;
        __int128 cur = 1;
        bool ok = true;
        for (int i = 0; i < y; i ++) 
        {
            cur *= m;
            if (cur > x) 
            {
                ok = false;
                break;
            }
        }
        if (ok) 
        {
            ans = m;
            l = m + 1;
        } 
        else 
        {
            h = m - 1;
        }
    }
    return ans;
}
bool isPerfectSquare(int n) 
{
    if (n < 0) return false;
    int r = getRoot(n, 2);
    return r * r == n;
}
vector<int> factors(int n) 
{
    vector<int> f;
    for (int i = 1; i * i <= n; i++) 
    {
        if (n % i == 0) 
        {
            f.push_back(i);
            if (i != n / i)
                f.push_back(n / i);
        }
    }
    return f; 
}
vector<int> prefixArr(vector<int>& arr) 
{
    int n = arr.size();
    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i ++) 
    {
        pref[i] = pref[i - 1] + arr[i - 1];
    }
    return pref;
}
vector<int> suffixArr(const vector<int>& arr) 
{
    int n = arr.size();
    vector<int> suff(n + 1, 0);
    for (int i = 1; i <= n; i ++) 
    {
        suff[i] = suff[i - 1] + arr[n - i];
    }
    return suff;
}
int gcd(int a, int b)
{
    return (!b ? a : gcd(b, a % b));
}
int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}
// number of 1-bits in x
// __builtin_popcountll(x);
// // 1 if popcount is odd, 0 if even
// __builtin_parityll(x);
// // count leading zeros in 64-bit
// __builtin_clzll(x);   // x != 0
// // count trailing zeros (use: lowest set bit, bit iteration)
// __builtin_ctzll(x);   // x != 0
// // index of highest 1-bit (use: power of 2 ≤ x)
// int msb = 63 - __builtin_clzll(x);
// // index of lowest 1-bit
// int lsb = __builtin_ctzll(x);
// // check if power of two
// (x > 0 && (x & (x - 1)) == 0);
// // check k-th bit
// (x >> k) & 1;
// // set k-th bit
// x | (1LL << k);
// // toggle k-th bit
// x ^ (1LL << k);
// // clear k-th bit
// x & ~(1LL << k);
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n * n);
    vector<vector<int>> ans(n, vector<int>(n, 0));
    map<int, int> freq;
    for (int i = 0; i < n * n; i ++)
    {
        cin >> a[i];
        freq[a[i]] += 1;
    }
    if (n % 2 == 0)
    {
        auto it = freq.begin();
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                while (it != freq.end() && it->second < 4)
                {
                    it++;
                }
                if (it == freq.end())
                {
                    cout << "NO" << endl;
                    return;
                }
                ans[i][j] = it->first;
                ans[i][n - j - 1] = it->first;
                ans[n - i - 1][j] = it->first;
                ans[n - i - 1][n - j - 1] = it->first;
                it->second -= 4;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (ans[i][j] == 0)
                {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
        cout << "YES" << endl;
        for (int i = 0; i < n; i ++)
        {
            for (int j = 0; j < n; j ++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        auto it = freq.begin();
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                while (it != freq.end() && it->second < 4)
                {
                    it++;
                }
                if (it == freq.end())
                {
                    cout << "NO" << endl;
                    return;
                }
                ans[i][j] = it->first;
                ans[i][n - j - 1] = it->first;
                ans[n - i - 1][j] = it->first;
                ans[n - i - 1][n - j - 1] = it->first;
                it->second -= 4;
            }
        }
        int mid = n / 2;
        // middle row
        for (auto it = freq.begin(); it != freq.end(); it++) 
        {
            while (it->second >= 2) 
            {
                bool placed = false;
                for (int j = 0; j < n / 2; j++) 
                {
                    if (ans[mid][j] == 0) 
                    {
                        ans[mid][j] = it->first;
                        ans[mid][n - j - 1] = it->first;
                        it->second -= 2;
                        placed = true;
                        break;
                    }
                }
                if (!placed) break; // ran out of space
            }
        }
        // middle column
        for (auto it = freq.begin(); it != freq.end(); it++) 
        {
            while (it->second >= 2) 
            {
                bool placed = false;
                for (int i = 0; i < n / 2; i++) 
                {
                    if (ans[i][mid] == 0) 
                    {
                        ans[i][mid] = it->first;
                        ans[n - i - 1][mid] = it->first;
                        it->second -= 2;
                        placed = true;
                        break;
                    }
                }
                if (!placed) break; // ran out of space
            }
        }
        // center
        for (auto it = freq.begin(); it != freq.end(); it++) 
        {
            if (it->second == 1)
            {
                ans[mid][mid] = it->first;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (ans[i][j] == 0)
                {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
        cout << "YES" << endl;
        for (int i = 0; i < n; i ++)
        {
            for (int j = 0; j < n; j ++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
}
int32_t main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
    {
        solve();
    }
}
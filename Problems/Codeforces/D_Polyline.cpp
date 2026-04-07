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
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    unordered_map<int, int> fx, fy;
    fx[x1] += 1;
    fx[x2] += 1;
    fx[x3] += 1;
    fy[y1] += 1;
    fy[y2] += 1;
    fy[y3] += 1;
    for (auto &p : fx)
    {
        if (p.second == 3)
        {
            cout << 1 << endl;
            return;
        }
        else if (p.second == 2)
        {
            if (x1 == x2)
            {
                if (y3 >= max(y1, y2) || y3 <= min(y1, y2))
                {
                    cout << 2 << endl;
                    return;
                }
            }
            if (x2 == x3)
            {
                if (y1 >= max(y2, y3) || y1 <= min(y2, y3))
                {
                    cout << 2 << endl;
                    return;
                }
            }
            if (x3 == x1)
            {
                if (y2 >= max(y3, y1) || y2 <= min(y3, y1))
                {
                    cout << 2 << endl;
                    return;
                }
            }
        }
    }
    for (auto &p : fy)
    {
        if (p.second == 3)
        {
            cout << 1 << endl;
            return;
        }
        else if (p.second == 2)
        {
            if (y1 == y2)
            {
                if (x3 >= max(x1, x2) || x3 <= min(x1, x2))
                {
                    cout << 2 << endl;
                    return;
                }
            }
            if (y2 == y3)
            {
                if (x1 >= max(x2, x3) || x1 <= min(x2, x3))
                {
                    cout << 2 << endl;
                    return;
                }
            }
            if (y3 == y1)
            {
                if (x2 >= max(x3, x1) || x2 <= min(x3, x1))
                {
                    cout << 2 << endl;
                    return;
                }
            }
        }
    }
    cout << 3 << endl;
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
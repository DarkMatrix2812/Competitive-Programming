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
struct Fenwick 
{
    int n;
    vector<long long> bit;
    Fenwick(int n) 
    {
        this->n = n;
        bit.assign(n + 1, 0);
    }
    void update(int i, long long val) 
    {
        for (; i <= n; i += i & -i)
            bit[i] += val;
    }
    long long query(int i) 
    {
        long long sum = 0;
        for (; i > 0; i -= i & -i)
            sum += bit[i];
        return sum;
    }
};
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i ++)
    {
        cin >> b[i];
    }
    vector<bool> block(k, true);
    for (int i = k + 1; i <= n; i ++) 
    {
        if (a[i] != a[i - k]) 
        {
            block[(i - 1) % k] = false;
        }
    }
    vector<int> val(k, - 1);;
    for (int i = 1; i <= n; i ++) 
    {
        int c = (i - 1) % k;
        if (!block[c]) 
        {
            if (b[i] != -1 && b[i] != a[i]) 
            {
                cout << "NO" << endl;
                return;
            }
        } 
        else 
        {
            if (b[i] != -1) 
            {
                if (val[c] != -1 && val[c] != b[i]) 
                {
                    cout << "NO" << endl;
                    return;
                }
                val[c] = b[i];
            }
        }
    }
    vector<int> freq(n + 1, 0);
    for (int i = 1; i <= k; i ++) 
    {
        int c = (i - 1) % k;
        if (block[c]) 
        {
            freq[a[i]] += 1;
        }
    }
    for (int i = 0; i < k; i++) 
    {
        if (block[i] && val[i] != -1) 
        {
            freq[val[i]] -= 1;
            if (freq[val[i]] < 0) 
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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
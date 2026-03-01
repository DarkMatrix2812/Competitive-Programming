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
int blocks(string s)
{
    int curr = s[0];
    int ans = 1;
    for (int i = 1; i < s.length(); i ++)
    {
        if (s[i] == curr) continue;
        else 
        {
            curr = s[i];
            ans += 1;
        }
    }
    return ans;
}
void solve()
{
    int n, h, k;
    cin >> n >> h >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    vector<int> pref_min_idx(n);
    pref_min_idx[0] = 0;
    for (int i = 1; i < n; i ++)
    {
        if (a[i] < a[pref_min_idx[i - 1]]) pref_min_idx[i] = i;
        else pref_min_idx[i] = pref_min_idx[i - 1];
    }
    vector<int> suff_max_idx(n);
    suff_max_idx[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i --)
    {
        if (a[i] > a[suff_max_idx[i + 1]]) suff_max_idx[i] = i;
        else suff_max_idx[i] = suff_max_idx[i + 1];
    }
    vector<int> pref = prefixArr(a);
    int rem = h % pref.back();
    int l = -1;
    int r = -1;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[suff_max_idx[i + 1]] > a[pref_min_idx[i]]  && pref[i + 1] + a[suff_max_idx[i + 1]] - a[pref_min_idx[i]] >= rem)
        {
            l = pref_min_idx[i];
            r = suff_max_idx[i + 1];
            break;
        }
    }
    if (l != -1 && r != -1)
    {
        swap(a[l], a[r]);
    }
    int t = 0;
    pref = prefixArr(a);
    t += (n * (h / pref.back()));
    int c = h / pref.back();
    rem = h % pref.back();
    if (rem > 0) c += 1;
    auto idx = lower_bound(pref.begin(), pref.end(), rem);
    t += (idx - pref.begin());
    t += (k * (c - 1));
    cout << t << endl;
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
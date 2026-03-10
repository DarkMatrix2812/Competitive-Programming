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
void solve()
{
    // GOT ABSOLUTELY COOKED IN THIS QUESTION - STILL UNABLE TO DEBUG IT
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) 
    {
        cin >> a[i];
    }
    if (m == 1)
    {
        cout << l - a.back() << endl;
        return;
    }
    if (n == 1)
    {
        int base = a[0] / m;
        int rem = a[0] % m;
        int mx = (rem >= 2 ? base + 1 : base);
        cout << mx + (l - a[0]) << endl;
        return;
    }
    if (m == 2)
    {
        long long d1 = 0, d2 = 0;
        int p = 0;
        for (int t = 1; t <= l; t++)
        {
            if(d1 <= d2) d1 += 1;
            else d2 += 1;
            if (p < n && a[p] == t)
            {
                if (d1 >= d2) d1 = 0;
                else d2 = 0;
                p += 1;
            }
        }
        cout << max(d1, d2) << endl;
        return;
    }
    vector<int> d(m);
    int tot = a[0];
    int base = tot / m;
    int rem = tot % m;
    for(int i = 0; i < m; i++)
    {
        d[i] = base + (i < rem ? 1 : 0);
    }
    int steps = max(0LL, n - m + 1);
    for (int i = 1; i <= steps; i++)
    {
        sort(d.begin(), d.end());
        tot -= d.back();     
        d.back() = 0;
        int gap = a[i] - a[i-1];
        tot += gap;
        base = tot / m;
        rem = tot % m;
        for(int j = 0; j < m; j ++)
        {
            d[j] = base + (j < rem);
        }
    }
    sort(d.begin(), d.end(), greater<int>());
    int ans = d[1];
    int ans2 = d[2];
    int sz = m - 1;
    for(int i = steps + 1; i < n; i++)
    {
        int gap = a[i] - a[i-1];
        int inc = gap / sz;
        int r = gap % sz;
        int add1 = inc + (r >= 2);
        int add2 = inc + (r >= 3);
        ans += add1;
        ans2 += add2;
        sz -= 1;
    } 
    if (a.back() == l) cout << ans2 << endl; // 2nd largest
    else cout << ans + (l - a.back()) << endl;
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